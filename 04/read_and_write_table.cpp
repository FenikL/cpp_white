#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
    fstream input("input.txt");
    if (input) {
        string N;
        string M;
        getline(input, N, ' ');
        getline(input, M);
        int N_int = stoi(N);
        int M_int = stoi(M);
        vector<string> values(M_int);
        for (int i = 0; i < N_int; ++i) {
            for (int j = 0; j < M_int; ++j) {
                string value;
                if (j == (M_int - 1)) {
                    getline(input, values[j], '\n');
                    cout << setw(10) << values[j];
                } else {
                    getline(input, values[j], ',');
                    cout << setw(10) << values[j] << " ";
                }
            }
            if (i != (N_int - 1)) {
                cout << endl;
            }
        }
    }
    return 0;
}