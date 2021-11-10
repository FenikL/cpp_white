#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> c;
    int len = v.size();
    for (int i = 0; i<len; ++i) {
        c.push_back(v[len - i - 1]);
    }
    return c;
}

int main() {
    vector<int> x, c;
    x = {1, 2, 3, 4, 5, 6};
    c = Reversed(x);
    for (int i : c) {
        cout << i << " ";
    }
    return 0;
}