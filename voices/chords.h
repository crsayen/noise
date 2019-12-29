#ifndef _INCL_GUARD
#define _INCL_GUARD
#include "../noiser.h"
#endif
#include <vector>

float quantized_lut[8] = {440.0,493.88,554.37,587.33,659.26,739.99,830.61,880.0};

float chord_lut[8][3] = {
    {1.0,1.2599318181818182,1.4983181818181819},
    {1.1224545454545454,1.3348409090909092,1.6817954545454545},
    {1.2599318181818182,1.4983181818181819,1.88775},
    {1.3348409090909092,1.6817954545454545,2.0},
    {1.4983181818181819,1.88775,2.2449090909090907},
    {1.6817954545454545,2.0,2.5198636363636364},
    {1.88775,2.2449090909090907,2.6696818181818185},
    {2.0,2.5198636363636364,2.9966363636363638}
};

float quantize_root(float *root, int* chord_idx){
    float lroot = *root;
    int iroot = (int)lroot;
    int idx;
    if (iroot > 880){ // TODO: maybe make this a switch. I don't know whether it matters.
        if (iroot > 14080){
            idx = ( iroot / 32) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 32.0f;
        }
        if (iroot > 7040){
            idx = ( iroot / 16) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 16.0f;
        }
        if (iroot > 3520){
            idx = ( iroot / 8) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 8.0f;
        }
        if (iroot > 1760){
            idx = ( iroot / 4) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 4.0f;
        }
        idx = ( iroot / 2) - 440;
        *chord_idx = (idx / 55);
        *root = quantized_lut[*chord_idx];
        return 2.0f;
    }
    else{
        if (iroot < 28){
            *chord_idx = 0;
            *root = quantized_lut[*chord_idx];
            return 0.03125;
        }
        if (iroot < 55){
            idx = (iroot * 16) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 0.0625f;
        }
        if (iroot < 110){
            idx = ( iroot * 8) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 0.125f;
        }
        if (iroot < 220){
            idx = ( iroot * 4) - 440;
            *chord_idx = (idx / 55);
            *root = quantized_lut[*chord_idx];
            return 0.25;
        }
        idx = ( iroot * 2) - 440;
        *chord_idx = (idx / 55);
        *root = quantized_lut[*chord_idx];
        return 0.5f;
    }

}

class Chords : public Voice {
    public:
    std::vector<Saw> saws;
    uint8_t _n_saws;
    Chords(uint8_t n_saws);
    ~Chords();
    void detune(float amount);
    float next(float frequency);
};

Chords::Chords(uint8_t n_saws){
    _n_saws = n_saws;
    for(int i = 0; i < n_saws; i++){
        saws.push_back(Saw());
    }
}

Chords::~Chords() {
    for(auto i : saws){
        delete(&i);
    }
}

float Chords::next(float frequency) {
    float out = 0.0f;
    float root = frequency * 48000;
    int idx;
    float chord[3];
    float oct = quantize_root(&root, &idx);
    for( int i = 0; i < 3; i++ ){
        chord[i] = chord_lut[idx][i];
    }
    int x = 0;
    for(auto &i : saws){
        out+= i.next(root * 2.0833333333e-05 * chord[x] * oct);
        x++;
    }
    out/= _n_saws;
    return out;
}