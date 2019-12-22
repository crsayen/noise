#include "noiser.h"

void ISR_tick(){
    static uint8_t n_ticks = 0;
    if(buffer.empty()){
        Serial.println("buffer empty");
        return;
    }
    uint16_t dac_code = buffer.front();

    buffer.pop();

    digitalWrite(SS,LOW); 
    SPI.transfer16(dac_code);
    digitalWrite(SS,HIGH); 

    if (n_ticks++ >= 48){
        tck = true;
        n_ticks = 0;
    }
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
  pinMode(SS, OUTPUT);
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
            unison_mapped = fmap(unison_read, 0.0f, 4094.0f, 0.001f, 0.5f);
            test.detune(unison_mapped);
        }
        last_unison = unison_read;
        fine = fmap(analogRead(A1), 0.0f, 4094.0f, 0.5f, 2.0f);  
        float v_adc = analogRead(VOCT);
        v_in = (v_adc - 3330.0f) / -413.0f;
        //Serial.println(v_in * 100);
        freq = pow(2,v_in) * low_c * fine * pow(2,oct) * sr_factor;
        //Serial.println(freq);
    }


    if (buffer.size() < 48){
        float n = test.next(freq);
        fcode =  32767.5f * n + 32767.5f;
        //Serial.println(n);
        code = (uint16_t)fcode;
        if ( code < 0 ){
            code = 0;
        } else if (code > 0xFFFF) code = 0xFFFF;

        noInterrupts();
        buffer.push(code);
        interrupts();  
    }else Serial.println("buffer full");    
}
