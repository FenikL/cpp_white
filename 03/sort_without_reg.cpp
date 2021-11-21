#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare_in_reg(const string& s1, const string& s2) {
    string low_s1;
    string low_s2;
    for (char c1 : s1) {
        low_s1.push_back(tolower(c1));
    }
    for (char c2 : s2) {
        low_s2.push_back(tolower(c2));
    }
    return low_s1 < low_s2;
}

int main() {
    int N;
    cin >> N;
    vector<string> strings(N);
    for (string& s: strings) {
        cin >> s;
    }
    sort(strings.begin(), strings.end(), compare_in_reg);
    for (string& s: strings) {
        cout << s << " ";
    }
    return 0;
}