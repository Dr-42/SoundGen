#pragma once
#include <string>

#define SAMPLE_RATE 48000

class Wave{
    public:
        Wave();
        void init(float frequency, float duration, float volume);
        ~Wave();
        bool writeWave();
        bool appendWave();
    private:
        float m_frequency, m_duration, m_volume;
        std::string m_filepath;
        float step = 0.03;
        float* samples;
};
