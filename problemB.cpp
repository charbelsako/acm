#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;
    infile.open("dahab.in");

    string n;
    infile >> n;

    printf("%d\n", n.length());
}