#pragma once
#include <string>

#define SAMPLE_RATE 48000

class Wave{
    public:
        Wave(float frequency, float duration, float volume);
        ~Wave();
        bool writeWave(std::string filepath);
    private:
        float m_frequency, m_duration, m_volume;
        float step = 0.03;
        float* samples;
};
