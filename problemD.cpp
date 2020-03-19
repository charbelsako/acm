#include <iostream>
#include <fstream>

using namespace std;

void calculate(int l, int r, int max_l, int max_r, int *count);

int main() {
    ifstream infile;
    infile.open("input/wcup.in");

    int x, y;

    while (x >= 0 || y >= 0) {
        int count = 0;
        infile >> x >> y;
        if (x < 0 || y < 0) {
            break;
        }
        calculate(0, 0, x, y, &count);
        printf("%d\n", count);
    }

}

void calculate(int l, int r, int max_l, int max_r, int *count) {
    
    if (l >= max_l && r >= max_r) {
        *count += 1;
        return;
    } 

    if (l < max_l) {
        int tl = l + 1;
        calculate(tl, r, max_l, max_r, count);
    }
    if (r < max_r) {
        int tr = r + 1;
        calculate(l, tr, max_l, max_r, count);
    }
}