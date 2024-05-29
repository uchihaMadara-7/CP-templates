// https://cses.fi/problemset/result/9394161/
#include <bits/stdc++.h>
using namespace std;

const int DIM = 8;

int main() {
    vector<int> queens(DIM);
    // Set the initial values to 0,1...7
    iota(queens.begin(), queens.end(), 0);

    int valid_num = 0;
    do {
        bool works = true;

        // Check the diagonals from the top-left to the bottom-right
        vector<bool> taken(DIM * 2 - 1);
        for (int c = 0; c < DIM; c++) {
            // Check if the diagonal with sum has been taken
            if (taken[c + queens[c]]) {
                works = false;
                break;
            }
            taken[c + queens[c]] = true;
        }

        // Check the diagonals from the top-right to the bottom-left
        taken = vector<bool>(DIM * 2 - 1);
        for (int c = 0; c < DIM; c++) {
            // queens[c] - c can be negative; the DIM - 1 offsets that
            if (taken[queens[c] - c + DIM - 1]) {
                works = false;
                break;
            }
            taken[queens[c] - c + DIM - 1] = true;
        }

        if (works) { valid_num++; }
    } while (next_permutation(queens.begin(), queens.end()));

    cout << valid_num << endl;
}