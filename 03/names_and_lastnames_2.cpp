#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string GetEmptyString() {
    string s;
    s.empty();
    return s;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        name_this_year[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_name_this_year[year] = last_name;
    }
    string GetFullName(int year) {
        string name_item = "None";
        string last_name_item = "None";
        for (auto& item : name_this_year) {

            if (item.first > year) {
                break;
            }
            name_item = item.second;
        }
        for (auto& item : last_name_this_year) {

            if (item.first > year) {
                break;
            }
            last_name_item = item.second;
        }
        if (name_item == "None" && last_name_item == "None") {
            return "Incognito";
        }
        else if (name_item == "None" && last_name_item != "None") {
            return last_name_item + " with unknown first name";
        }
        else if (name_item != "None" && last_name_item == "None") {
            return name_item + " with unknown last name";
        }
        return (name_item + " " + last_name_item);
    }
    string GetFullNameWithHistory(int year) {
        vector<string> history_names = {};
        vector<string> history_last_names = {};
        string previous = "flag!";
        for (auto &item: name_this_year) {

            if (item.first > year) {
                break;
            }
            if (previous != item.second) {
                history_names.push_back(item.second);
            }
            previous = item.second;
        }
        previous = "flag!";
        for (auto &item: last_name_this_year) {

            if (item.first > year) {
                break;
            }
            if (previous != item.second) {
                history_last_names.push_back(item.second);
            }
            previous = item.second;
        }
        if (history_names.empty() && history_last_names.empty()) {
            return "Incognito";
        } else if (history_names.empty() && history_last_names.size() > 0) {
            return history_last_names[history_last_names.size() - 1] + GetStringHistoryLast(history_last_names) + " with unknown first name";
        } else if (history_names.size() > 0 && history_last_names.empty()) {
            return history_names[history_names.size() - 1] + GetStringHistory(history_names) + "with unknown last name";
        } else if (history_names.size() > 0 && history_last_names.size() > 0) {
            return history_names[history_names.size() - 1]  + GetStringHistory(history_names) +
                   history_last_names[history_last_names.size() - 1] + GetStringHistoryLast(history_last_names);
        }
    }
private:
    // приватные поля
    map<int, string> name_this_year;
    map<int, string> last_name_this_year;
    string GetStringHistoryLast(const vector<string>& history_names) {
        string result = "";
        auto len = history_names.size();
        if (len == 0) {
            return result;
        }
        else {
            for (auto i = 1; i < len; ++i) {
                if (i == 1) {
                    result += " (";
                }
                result += history_names[len - i - 1];
                if (i == (len - 1)) {
                    result += ")";
                } else {
                    result += ", ";
                }
            }
        }
        return result;
    }
    string GetStringHistory(const vector<string>& history_names) {
        string result = " ";
        auto len = history_names.size();
        if (len == 0) {
            return result;
        }
        else {
            for (auto i = 1; i < len; ++i) {
                if (i == 1) {
                    result += "(";
                }
                result += history_names[len - i - 1];
                if (i == (len - 1)) {
                    result += ") ";
                } else {
                    result += ", ";
                }
            }
        }
        return result;
    }
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
