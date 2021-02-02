#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream infile;
    infile.open("input/gunshots.in");

    // calculate new region
    // right_side = R - num
    // left_side = R - num - num if not zero
    // same thing for y

    int t;
    infile >> t;
    for (int i = 0; i < t; i++){
        int R, T, x, y, num_folds;
        infile >> R >> T >> x >> y >> num_folds;

        vector<vector<int>> folds;

        folds.push_back({0, R, 0, T});


        for (int j = 0; j < num_folds; j++) {
            char dir;
            int num;
            infile >> dir >> num;
           
            if (num > R || num > T) {
                continue;
            }

            int right_side = R, left_side = 0, ls = 0, rs = T;

            if (dir == 'X') {
                left_side = (num - (R - num));
                R = num;
            }else{
                ls = num - (T - num);
                T = num;
            }

            int size = folds.size();
            for (int k = 0; k < size; k++) {
                if (dir == 'X'){ 
                    right_side = R;
                    folds.push_back({left_side, right_side, ls, rs});
                }else{ 
                    rs = T;
                    folds.push_back({left_side, right_side, ls, rs});
                } 
            }
        }

        int count = 0;
        if (x > R || y > T){
            cout << count;
            return 0;
        }

        int size = folds.size();
        for (int i = 0; i < size; i++){
            if( x >= folds[0][0] && x <= folds[0][1] && y >= folds[0][2] && folds[0][3]){
                count++;
            }    
        }

        //for (vector<int> k : folds){
        //    for (int l : k){
        //        cout << l << " ";
        //    }
        //    cout << endl;
        //}

        cout << count << endl;
    }
}
