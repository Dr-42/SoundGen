#include "Wave.h"
#include <math.h>
#include <iostream>
#include <fstream>

#define PI 3.14159265358979323846264338327

Wave::Wave(){
    m_volume = 0.0f;
    m_frequency = 0.0f;
    m_duration = 0.0f;
    m_filepath = "bin/wav.bin";
}

void Wave::init(float frequency, float duration, float volume){
    m_volume = volume;
    m_frequency = frequency;
    m_duration = duration;

    int nSample = duration * SAMPLE_RATE; 
    samples = new float[nSample];
    
    float x = 0;

    for(int i = 0; i < nSample; i++){
        x += frequency/(float)SAMPLE_RATE;
        samples[i] = volume * sin(2 * PI * x);
    }
}


Wave::~Wave(){
    delete samples;
}

bool Wave::writeWave(){
    int i = 0;
    std::ofstream out(m_filepath.c_str(), std::ios::out | std::ios::binary);
    if(!out){
        std::cout << "Cannot Open file.\n";
        return false;
    }
    int nSamples = SAMPLE_RATE * m_duration;
    float samples_m[nSamples];
    for(int i = 0; i < nSamples; i++)
    {
        samples_m[i] = samples[i];
    }
    out.write((char *) samples_m, sizeof(samples_m));
    out.close();
    return true;
}

bool Wave::appendWave(){
    int i = 0;
    std::ofstream out(m_filepath.c_str(), std::ios_base::app | std::ios::binary);
    if(!out){
        std::cout << "Cannot Open file.\n";
        return false;
    }
    int nSamples = SAMPLE_RATE * m_duration;
    float samples_m[nSamples];
    for(int i = 0; i < nSamples; i++)
    {
        samples_m[i] = samples[i];
    }
    out.write((char *) samples_m, sizeof(samples_m));
    out.close();
    return true;
}
