#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string a, b, c;
    vector<string> all_strings;
    cin >> a >> b >> c;
    all_strings = {a, b, c};
    sort(all_strings.begin(), all_strings.end());
    cout << all_strings[0];
    return 0;
}

