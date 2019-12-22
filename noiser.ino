#include "noiser.h"

void ISR_tick(){
    static uint8_t n_ticks = 0;
    uint16_t dac_code = 0;
    if(buffer.empty()){
        Serial.println("buffer empty");
        return;
    }
    dac_code = buffer.front();
    buffer.pop();

    digitalWrite(ss,LOW); 
    SPI.transfer16(code);
    digitalWrite(ss,HIGH); 

    if (n_ticks >= 48){
        tck = true;
        n_ticks = 0;
    }
    n_ticks++;
}

void ISR_octave_up(){
  if (millis() - lastl < BOUNCE_DURATION) return;
  lastl = millis();
  if (oct < 4) oct++;
}

void ISR_octave_down(){
  if (millis() - lastl < BOUNCE_DURATION) return;
  lastl = millis();
  if (oct > -8) oct--;
}

void setup() {
  Serial.begin(9600);
  analogReadAveraging(1);
  analogReadRes(12);
  SPI.begin();
  SPI.setDataMode (SPI_MODE3); 
  pinMode(ss, OUTPUT);
  int inputs[5] = {VOCT,OCT_UP,OCT_DOWN,A5,A9};
  for(int i = 0; i < 5; i++){
      pinMode(inputs[i], INPUT);
  }
  attachInterrupt(digitalPinToInterrupt(OCT_UP), ISR_octave_up, RISING);
  attachInterrupt(digitalPinToInterrupt(OCT_DOWN), ISR_octave_down, RISING);
  tick.priority(128);
  tick.begin(ISR_tick, 20.8333);
}

void loop() {
    if(tck){
        tck == false;
        unison_read = analogRead(A9);
        if (abs(unison_read - last_unison) > 10){
            unison_mapped = fmap(adc, 0.0f, 4094.0f, 0.001f, 0.5f);
            test.detune(unison_mapped);
        }
        last_unison = unison_read;
        fine = fmap(analogRead(A1), 0.0f, 4094.0f, 0.5f, 2.0f);  
        v_in = (analogRead(VOCT) - 3330.0f) / -413.0f;
        freq = pow(2,v_in) * low_c * fine * pow(2,oct) * sr_factor;
    }

    fcode =  32767.5f * test.next(freq) + 32767.5f;
    code = (uint16_t)fcode;
    if ( code < 0 ){
        code = 0;
    } else if ( code > 0xFFFF) {
        code = 0xFFFF;
    }

    noInterrupts();
    if (buffer.size() < 48){
        buffer.push(code);
    }else{
        Serial.println("buffer full");
    }
    interrupts();  
}
