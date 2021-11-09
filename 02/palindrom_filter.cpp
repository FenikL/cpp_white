#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string x) {
    int len = x.size();
    for (int i=0; i < len/2; ++i) {
        if (x[i] != x[len - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;
    for (string x : words) {
         if (IsPalindrom(x) && x.size() >= minLength) {
             result.push_back(x);
         }
    }
    return result;
}

int main() {
    return 0;
}