#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int q, d;
    int month = 0;
    string command, s;
    cin >> q;
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> affairs (days[0]);
    for (int _=0; _<q; _++) {
        cin >> command;
        if (command == "ADD") {
            cin >> d >> s;
            affairs[d-1].push_back(s);
        }
        if (command == "DUMP") {
            cin >> d;
            cout << affairs[d-1].size() << " ";
            for (string str : affairs[d-1]) {
                cout << str << " ";
            }
            cout << endl;
        }
        if (command == "NEXT") {
            month++;
            if (month > 11) {
                month = 0;
            }
            if (days[month] > days[month - 1]) {
                affairs.resize(days[month]);
            }
            else {
                for (int ld=days[month]; ld<days[month-1]; ld++) {
                    for (string str : affairs[ld]) {
                        affairs[days[month]-1].push_back(str);
                    }
                }
                affairs.resize(days[month]);
            }
        }
    }
    return 0;
}