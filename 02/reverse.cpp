#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    int len = v.size();
    for (int i=0; i<(len/2); ++i) {
        int tmp = v[i];
        v[i] = v[len - i - 1];
        v[len - i -1] = tmp;
    }
}

int main() {
    vector<int> x;
    x = {1, 2, 3, 4, 5, 6};
    Reverse(x);
    for (int i : x) {
        cout << i << " ";
    }
    return 0;
}