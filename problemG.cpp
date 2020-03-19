#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;
    infile.open("input/string.in");

    char c;
    int k;
    infile >> k >> c;

    printf("%c\n", ((int)c - 97) % 26 + k + 97);
}