#include <iostream>
#include <string>

using namespace std;

void permutations(int vp, string b, char va[], string a, string c, string d);

int count = 0;

int main() {
    string a = "s";
    string b = "s";

    string c = "ss";
    string d = "ss";

    // TODO: this needs to be a dynamically sized array.
    // Get the unique variables in a and d and put them in it.
    char va[1] = {'s'};
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
                pos = b.find(va[vp], pos+1); // find next ocurrence
            } while(pos != string::npos);
        }

        auto pos2 = c.find(va[vp]);
        if(pos2 != std::string::npos) {
            do {   
                d[pos2] = (char) i+48;   // overwrite
                pos2 = c.find(va[vp], pos2+1); // find next ocurrence
            } while(pos2 != string::npos);
        }

        // ERR: Number 1 needs to change
        if (vp < 1) {
            int t_vp = vp;
            t_vp++;
            permutations(t_vp, b, va, a, c, d);
        } else {
            if (b.compare(d) < 0) {
                count++;
            }
            return;
        }
    }
}
