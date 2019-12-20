#ifndef _INCL_GUARD
#define _INCL_GUARD
#include "../noiser.h"
#endif

class Saw : public Oscillator {
    public:
    Saw() {}
    ~Saw() {}
    float next(float frequency){
        frequency += frequency * _detune;
        _phase = (_phase > 1.0f) ? _phase -1.0f : _phase;
        float val = (_phase * 2.0f) - (1 + polyblep(frequency, _phase));
        _phase+= frequency;
        return val;
    }
};