#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int Q, stop_count;
    cin >> Q;
    string command, bus, stop;
    map<string, vector<string>> stops_for_bus;
    map<string ,vector<string>> buses_for_stop;
    for (int i=0; i<Q; ++i) {
        cin >> command;
        if (command == "NEW_BUS") {
            cin >> bus;
            cin >> stop_count;
            for (int _=0; _<stop_count; ++_) {
                cin >> stop;
                stops_for_bus[bus].push_back(stop);
            }
            for (string& s : stops_for_bus[bus]) {
                buses_for_stop[s].push_back(bus);
            }
        }
        if (command == "STOPS_FOR_BUS") {
            cin >> bus;
            if (stops_for_bus.count(bus) == 0) {
                cout << "No bus" << endl;
            }
            else {
                for (string& s : stops_for_bus[bus]) {
                    cout << "Stop " << s << ": ";
                    if (buses_for_stop[s].size() == 1) {
                        cout << "no interchange";
                    }
                    for (string b : buses_for_stop[s]) {
                        if (b != bus) {
                            cout << b << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        if (command == "BUSES_FOR_STOP") {
            cin >> stop;
            if (buses_for_stop.count(stop) == 0) {
                cout << "No stop";
            }
            else {
                for (string& b : buses_for_stop[stop]) {
                    cout << b << " ";
                }
            }
            cout << endl;
        }
        if (command == "ALL_BUSES") {
            if (stops_for_bus.empty()) {
                cout << "No buses" << endl;
            }
            else {
                for (const auto& item : stops_for_bus) {
                    cout << "Bus " << item.first << ": ";
                    for (const string& s: item.second) {
                        cout << s << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}