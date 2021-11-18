#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int Q;
    string command, country, capital, new_capital, old_country_name, new_country_name;
    cin >> Q;
    map<string, string> directory_of_capitals;
    for (int i=0; i<Q; ++i) {
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            cin >> country >> new_capital;
            if (directory_of_capitals.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " <<new_capital;
            }
            else if (directory_of_capitals[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital";
            }
            else {
                cout << "Country " << country << " has changed its capital from "
                << directory_of_capitals[country] << " to " << new_capital;
            }
            directory_of_capitals[country] = new_capital;
            cout << endl;
        }
        if (command == "RENAME") {
            cin >> old_country_name >> new_country_name;
            if (directory_of_capitals.count(old_country_name) == 0 || directory_of_capitals.count(new_country_name) ==1
            || old_country_name == new_country_name) {
                cout << "Incorrect rename, skip";
            }
            else {
                capital = directory_of_capitals[old_country_name];
                directory_of_capitals.erase(old_country_name);
                directory_of_capitals[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital " << capital
                << " has been renamed to " <<new_country_name;
            }
            cout << endl;
        }
        if (command == "ABOUT") {
            cin >> country;
            if (directory_of_capitals.count(country) == 0) {
                cout << "Country " <<  country << " doesn't exist";
            }
            else {
                cout << "Country " << country << " has capital " << directory_of_capitals[country];
            }
            cout << endl;
        }
        if (command == "DUMP") {
            if (directory_of_capitals.empty()) {
                cout << "There are no countries in the world";
            }
            else {
                for (const auto& item : directory_of_capitals) {
                    cout << item.first << "/" << item.second << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}