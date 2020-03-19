// Title: Bitwise OR
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream input;
    input.open("input/or.in");

    int t;
    input >> t;

    int R, L;
    for (int i = 0; i < t; i++) {
        int count = 0;
        input >> L >> R;
        for (int a = L; a <= R; a++) {
            for (int b = L; b <= R; b++) {
                if ((a+b) == (a|b) ){
                    count ++;
                }
            }
        } 
        printf("%d\n", count % (int)(pow(10,9) + 7) );
    }
}