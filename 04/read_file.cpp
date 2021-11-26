#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Error!";
    }
    return 0;
}