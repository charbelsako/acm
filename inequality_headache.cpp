#include <iostream>
#include <string>

using namespace std;

void permutations(int vp, string b, char va[], string a, string c, string d);

int count = 0;

int main() {
    string a = "xy";
    string b = "xy";

    string c = "yx";
    string d = "yx";

    printf("%s\n", b.c_str());
    
    char va[2] = {'x', 'y'};
    int vp = 0;
    
    permutations(vp, b, va, a, c, d);
    
    cout << count << endl;
}

void permutations(int vp, string b, char va[], string a, string c, string d) {
    for (int i = 1; i < 10; i++) {
        auto pos = a.find(va[vp]);
        if(pos != std::string::npos) {
            do {   
                b[pos] = (char) i+48;   // overwrite
                pos = b.find(va[vp], pos); // find next ocurrence
            } while(pos != std::string::npos);
        }

        auto pos2 = c.find(va[vp]);
        if(pos2 != std::string::npos) {
            do {   
                d[pos2] = (char) i+48;   // overwrite
                pos2 = c.find(va[vp], pos2); // find next ocurrence
            } while(pos2 != std::string::npos);
        }
        
        if (vp < 2) {
            // cout << "recursive" << endl;
            // a is a pointer, hence the bug
            int t_vp = vp;
            t_vp++;
            permutations(t_vp, b, va, a, c, d);
        } else {
            // perform inequality if
            // printf("%s\n", b.c_str());
            count++;
            return;
        }
    }
}
