#ifndef _INCL_GUARD
#define _INCL_GUARD
#include "utility.h"
#include "assets/sin_table.h"
#include "oscillators/oscillator.h"
#include "oscillators/sine.h"
#include "oscillators/triangle.h"
#include "oscillators/saw.h"
#include "oscillators/square.h"
#include "voices/voice.h"
#include "voices/supersaw.h"
#include "voices/analog.h"
#endif
#include <SPI.h>
#include <TimerOne.h>
#define VOCT A8
#define OCT_UP 2
#define OCT_DOWN 1
#define FREQ_DIVISOR 8190.0f
#define BOUNCE_DURATION 200

float low_c =  16.35159781;
float sr_factor = 2.0833333333e-05;
//std::vector<std::unique_ptr<Oscillator> > oscs;
Supersaw test;

const unsigned int ss = 8;
const float vref = 3.3;
