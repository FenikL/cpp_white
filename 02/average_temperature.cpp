#include <iostream>
#include <vector>

using namespace std;

vector<int> SearchDays(const vector<int>& temp, const int& average) {
    vector<int> result;
    for (int i=0; i<temp.size(); ++i) {
        if (temp[i] > average) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int average = 0;
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int& i : temp) {
        cin >> i;
        average += i;
    }
    average = average / n;
    vector<int> result = SearchDays(temp, average);

    cout << result.size() << "\n";

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}