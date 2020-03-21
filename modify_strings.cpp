#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "what";
    printf("Original: %s\n", s.c_str());
    s[0] = (char) 98;
    s[0] =  'a';
    printf("New: %s\n", s.c_str());

    string a = "xy";
    // Other ways to perform the same thing


}