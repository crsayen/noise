#ifndef _INCL_GUARD
#define _INCL_GUARD
#include "../noiser.h"
#endif

class Oscillator {
  public:
    float _detune;
    float _phase;
    Oscillator() { 
      _detune = 0.0f;
      _phase = 0.0f;
    }
    ~Oscillator() { }
};
