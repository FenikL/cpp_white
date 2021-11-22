#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        strings_unsorted.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(strings_unsorted.begin(), strings_unsorted.end());
        return strings_unsorted;
    }
private:
    vector<string> strings_unsorted;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
