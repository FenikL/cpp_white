#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool absolute(int x, int y) {
    if (x < 0 && y > 0) {
        return (-x < y);
    }
    if (y < 0 && x > 0) {
        return (x < -y);
    }
    if (x < 0 && y < 0) {
        return (-x < -y);
    }
    return (x < y);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& i : A) {
        cin >> i;
    }
    sort(A.begin(), A.end(), absolute);
    for (const auto& i : A) {
        cout << i << " ";
    }
    return 0;
}
