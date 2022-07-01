#include <stdio.h>
#include "Wave.h"
#include "Notes.h"

void write(float* notes, float* times, int n){
    Wave waves[n];
    for(int i = 0; i < n; i++)
    {
        waves[i].init(notes[i], times[i], 0.5f);    
        if(i == 0){
            waves[i].writeWave();
        }else{
            waves[i].appendWave();
        }
    }

}

int main(){
    float notes[] = { C4, C4, G4, G4, A4, A4, G4, F4, F4, E4, E4, D4, D4, C4, G4, G4, F4, F4, E4, E4, D4, G4, G4, F4, F4, E4, E4, D4,C4, C4, G4, G4, A4, A4, G4, F4, F4, E4, E4, D4, D4, C4};
    int n = sizeof(notes)/ sizeof(float);
    float times[] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0,0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0,0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0};
    write(notes, times, n);
    return 0;
}

