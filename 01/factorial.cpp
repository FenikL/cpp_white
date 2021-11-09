#include <iostream>

using namespace std;

int GetFactorial(int n) {
    int f = 1;
    if (n < 2) {
        return f;
    }
    for (int i=1; i <= n; ++i) {
        f *= i;
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    cout << GetFactorial(n);
    return 0;
}