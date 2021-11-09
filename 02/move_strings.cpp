#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (string s : source) {
        destination.push_back(s);
    }
    source.clear();
}

int main() {
    vector<string> a, b;
    a = {"a", "b", "c"};
    b = {"z"};
    MoveStrings(a, b);
    for (string s : a) {
        cout << s;
    }
    cout << "\n";
    for (string s : b) {
        cout << s;
    }
    return 0;
}