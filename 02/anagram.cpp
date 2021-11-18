#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounters(const string& word){
    map<char, int> char_counters;
    for (char c : word) {
        ++char_counters[c];
    }
    return char_counters;
}

int main() {
    int N;
    cin >> N;
    string w1, w2;
    for (int i=0; i<N; ++i) {
        cin >> w1 >> w2;
        if (BuildCharCounters(w1) == BuildCharCounters(w2)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}