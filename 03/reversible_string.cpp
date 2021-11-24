#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& s) {
       str = s;
    }
    void Reverse() {
        int len = str.size();
        for (int i = 0; i < (len/2); ++i) {
            swap(str[i], str[len-1-i]);
        }
    }
    string ToString() const{
        return str;
    }
private:
    string str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
