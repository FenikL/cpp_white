#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
    int Q, N, number;
    cin >> Q;
    map<set<string>, int> route_numbers;
    for (int i=0; i<Q; ++i) {
        set<string> route;
        string stop;
        cin >> N;
        for (int j=0; j<N; ++j) {
            cin >> stop;
            route.insert(stop);
        }
        if (route_numbers.count(route) == 0) {
            number = route_numbers.size();
            route_numbers[route] = number + 1;
            cout << "New bus " << number + 1;
        }
        else {
            cout << "Already exists for " << route_numbers[route];
        }
        cout << endl;
    }
    return 0;
}