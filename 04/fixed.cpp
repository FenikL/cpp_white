#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    fstream input("input.txt");
    double value;
    if (input) {
        cout << fixed << setprecision(3);
        while (input >> value) {
            cout << value << endl;
        }
    } else {
        cout << "error!";
    }
    return 0;
}

