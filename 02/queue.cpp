#include <iostream>
#include <vector>
#include <string>

using namespace std;

void GetWorryCount(const vector<string>& queue) {
    int result = 0;
    for (string s : queue) {
        if (s == "WORRY") {
            result++;
        }
    }
    cout << result << endl;
}

int main() {
    int q, count, len, ind;
    string command;
    vector<string> queue;
    cin >> q;
    for (int _=0; _<q; ++_) {
        cin >> command;
        if (command == "WORRY_COUNT") {
            GetWorryCount(queue);
        }
        if (command == "COME") {
            cin >> count;
            if (count > 0) {
                for (int i=0; i < count; ++i) {
                    queue.push_back("CALMLY");
                }
            }
            else {
               len = queue.size();
               queue.resize(len+count);
            }
        }
        if (command == "WORRY") {
            cin >> ind;
            queue[ind] = "WORRY";
        }
        if (command == "QUIET") {
            cin >> ind;
            queue[ind] = "CALMLY";
        }
    }
    return 0;
}