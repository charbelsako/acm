#include <iostream>

using namespace std;

void permutations(int vp, string b, char va[]);
int count = 0;

int main() {
    string a = "xy";
    auto b = string{2, '_'};
    printf("%s\n", b);
    char va[2] = {'x', 'y'};
    int vp = 0;
    permutations(vp, b, va); 
    cout << count << endl;
}

void permutations(int vp, string b, char va[]){
    for (int i = 0; i < 9; i++) {
        auto pos = b.find(va[vp]);
        if(pos != std::string::npos) {
            do {   
                b[pos] = i;   // overwrite
                pos = b.find(va[vp], pos); // find next ocurrence
            } while(pos != std::string::npos);
        }

        if (vp < 2) {
            cout << "recursive" << endl;
            // a is a pointer, hence the bug
            permutations(++vp, b, va);
        } else {
            // perform inequality if
            printf("%s\n", b);
            count++; 
            return;
        }
    }
}
