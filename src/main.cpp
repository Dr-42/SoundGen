#include <stdio.h>
#include "Wave.h"
#include "Notes.h"

void write(float* notes, int n){
    Wave waves[n];
    for(int i = 0; i < n; i++)
    {
        waves[i].init(notes[i], 0.5f, 0.9f);    
        if(i == 0){
            waves[i].writeWave();
        }else{
            waves[i].appendWave();
        }
    }

}

int main(){
    float notes[] = { C5, C5, G5, G5, A5, A5, G5, G5 };
    int n = sizeof(notes)/ sizeof(float);
    write(notes, n);
    return 0;
}

