#include <iostream>

using namespace std;

int main() {
    int a, b;
    int q, r;
    int result;

    cin >> a >> b;

    if (b > a) {
        int c = b;
        b = a;
        a = c;
    }

    r = a % b;
    result = b;

    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
        result = b;
    }

    cout << result;

    return 0;
}