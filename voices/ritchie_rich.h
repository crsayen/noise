#ifndef _INCL_GUARD
#define _INCL_GUARD
#include "../noiser.h"
#endif

class Ritchie_rich : public Voice {
    public:
    float levels[4];
    float pitches[4];
    Sine sine;
    Saw saw;
    Triangle triangle;
    Square square;
    Ritchie_rich();
    ~Ritchie_rich();
    float next(float frequency);
};

Ritchie_rich::Ritchie_rich(){
    sine = Sine();
    saw = Saw();
    triangle = Triangle();
    square = Square();
    square._pulsewidth = 0.3;
    levels[0] = 0.4f;
    levels[1] = 0.1f;
    levels[2] = 0.4f;
    levels[3] = 0.1f;
    pitches[0] = 0.5001f;
    pitches[1] = 2.01f;
    pitches[2] = 0.997f;
    pitches[3] = 2.0f;
}

Ritchie_rich::~Ritchie_rich() {
    delete(&sine);
    delete(&saw);
    delete(&triangle);
    delete(&square);
}

float Ritchie_rich::next(float frequency) {
    float out = 0.0f;
    out+= sine.next(frequency * pitches[0]) * levels[0];
    out+= saw.next(frequency * pitches[1]) * levels[1];
    out+= square.next(frequency * pitches[2]) * levels[2];
    out+= triangle.next(frequency * pitches[3]) * levels[3];
    return out;
}