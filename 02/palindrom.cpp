#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom (string x) {
    bool result = true;
    int len = x.size();
    for (int i = 0; i < len/2; ++i) {
        if (x[i] != x[len - i - 1]) {
            return false;
        }
    }
    return result;
}

int main() {
    string x;
    cin >> x;
    cout << IsPalindrom(x);
    return 0;
}