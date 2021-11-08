#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> bin_n;
    cin >> n;
    while (n != 0) {
        bin_n.push_back(n%2);
        n = n / 2;
    }


    for (int i=bin_n.size()-1; i != -1; --i){
        cout << bin_n[i];

    }

    return 0;
}