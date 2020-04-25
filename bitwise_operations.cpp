#include <iostream>

using namespace std;

int main() {
    // 00000100
    int x = 4;
    // 00000101
    int y = 5;
    // 00000011
    int a = 3;
    // 00000001
    int b = 1;
    // or 
    printf("%d", x | y);
    // and
    printf("%d", x & y);
    // xor gives zero
    printf("%d", a ^ a);
    // not
    printf("%d", ~x);

    return 0;
}
