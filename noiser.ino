#include "noiser.h"
#define BOUNCE_DURATION 200
float fcode = 0.0;
int unison_read = 0;
float unison_detune = 0.0;
int last_unison = 0;
volatile long lastl;
volatile uint16_t code = 0;
volatile bool tck = true;
volatile float oct = 0.0f;
IntervalTimer tick;

void ISR_tick(){
  if ( code < 0 ){
    code = 0;
  } else if ( code > 0xFFFF) {
    code = 0xFFFF;
  }
  digitalWrite(ss,LOW); 
  SPI.transfer16(code);
  digitalWrite(ss,HIGH); 
}

void ISR_octave_up(){
  if(millis() - lastl < BOUNCE_DURATION)return;
  lastl = millis();
  if(oct < 4){
    oct+= 1;
  }
  return;
}

void ISR_octave_down(){
  if(millis() - lastl < BOUNCE_DURATION)return;
  lastl = millis();
  if(oct > -8){
    oct-= 1;
  }
  return;
}

void setup() {
  Serial.begin(9600);
  analogReadAveraging(1);
  analogReadRes(12);
  SPI.begin();
  SPI.setDataMode (SPI_MODE3); 
  pinMode(ss, OUTPUT);
  pinMode(VOCT, INPUT);
  pinMode(OCT_UP, INPUT);
  pinMode(OCT_DOWN, INPUT);
  attachInterrupt(
    digitalPinToInterrupt(OCT_UP), 
    ISR_octave_up, 
    RISING
  );
  attachInterrupt(
    digitalPinToInterrupt(OCT_DOWN), 
    ISR_octave_down, 
    RISING
  );
  pinMode(A5, INPUT);
  pinMode(A9, INPUT);
  tick.priority(128);
  tick.begin(ISR_tick, 20.8333);
}

void loop() {
    unison_read = analogRead(A9);
    if (abs(unison_read - last_unison) > 10){
      float unison_mapped = fmap(adc, 0.0f, 4094.0f, 0.001f, 0.5f);
      test.detune(unison_mapped);
    }
    last_unison = unison_read;
    
    //map fine tune to 1/2-2: -1 oct - +1 oct
    int fine_adc = analogRead(A1);
    float fine = fmap(fine_adc, 0.0f, 4094.0f, 0.5f, 2.0f);  
    
    // get CV in
    float v_in = analogRead(VOCT);

    // map CV to v/oct: 0 - 8
    float note = (v_in - 3330.0) / -413.0;

    // freq to hz
    float freqhz = (pow(2,note) * low_c);

    // oct is  0.25 | 0.5 | 1 | 2 | 4 
    freqhz = freqhz * pow(2,oct);


    // fine is between 0.5 and 2
    freqhz = freqhz * fine;

    // divide by sample rate
    freqhz*= sr_factor;

    // get next sample code
    fcode =  32767.5f * test.next(freqhz) + 32767.5f;

        
    // set the code for the DAC
    noInterrupts();
    code = (uint16_t)fcode;
    interrupts();  
}
