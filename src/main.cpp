#include <stdio.h>
#include "Wave.h"

int main(){
    Wave wave(440.0f, 1.5, 0.9f);
    wave.writeWave("bin/wav.bin");
    return 0;
}

