#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;
    infile.open("input/sum.in");

    int t;
    infile >> t;

    int n;
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        infile >> n;
        float sum = 0;
        for (int j = 1; j <= n*n; j += n+1) {
            sum += j;
        }
        printf("%.8f\n", sum);
    }
}