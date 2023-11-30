#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    char c = '\0';
    int sad = 0;
    int happy = 0;

    while(scanf("%c",&c) != 0) {
        if (c == '\n') break;
        if (c == 'S' || c == 'A' || c == 'D') {
            sad++;
        }
        if (c == 'H' || c == 'A' || c == 'P' || c == 'Y') {
            happy++;
        }
    }

    double answer = happy + sad;
    happy + sad != 0 ? answer = happy * 100.0 / answer : answer = 50.00;
    
    printf("%.2f", round(answer * 100) / 100);
}