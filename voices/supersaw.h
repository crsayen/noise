#ifndef _INCL_GUARD
#define _INCL_GUARD
#include "../noiser.h"
#endif

class Supersaw : public Voice {
    public:
    std::vector<Saw> saws;
    uint8_t _n_saws;
    Supersaw(uint8_t n_saws) {
        _n_saws = n_saws;
        for(int i = 0; i < n_saws; i++){
            saws.push_back(Saw());
        }
    }
    ~Supersaw() {
        for(auto i = saws.begin(); i != saws.end(); i++){
            delete(i);
        }
    }
    float detune(float amount) {
        uint8_t osc = 0;
        uint8_t half = _n_saws / 2;
        float offset = (_n_saws & 1) ? 0.0f : 0.5f;
        for(auto i = saws.begin(); i != saws.end(); i++) {
            i.detune = (osc - half + offset) * amount;
            osc++;
        }
    }
    float next(float frequency) {
        float out = 0.0f;
        for(auto i = saws.begin(); i != saws.end(); i++){
            out+= i.next(frequency);            
        }
        out/= _n_saws;
        return out;
    }
};