#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

void Add(map<string, set<string>>& m, const string& w1, const string& w2) {
    m[w1].insert(w2);
    m[w2].insert(w1);
}

int main() {
    int Q;
    string command, w, w1, w2;
    map<string, set<string>> synonyms;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> command;
        if (command == "ADD") {
            cin >> w1 >> w2;
            Add(synonyms, w1, w2);
        }
        if (command == "COUNT") {
            cin >> w;
            cout << synonyms[w].size() << endl;
        }
        if (command == "CHECK") {
            cin >> w1 >> w2;
            if (synonyms[w1].count(w2) == 0) {
                cout << "NO";
            } else {
              cout << "YES";
            }
            cout << endl;
        }
    }
    return 0;
}