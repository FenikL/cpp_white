#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N;
    set<string> strings;
    cin >> N;
    string s;
    for (int i=0; i<N; ++i) {
        cin >> s;
        strings.insert(s);
    }
    cout << strings.size();
    return 0;
}