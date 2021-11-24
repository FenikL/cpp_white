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

class Person {
public:
    Person(const string& name,
           const string& last_name, int year) {
        name_this_year[year] = name;
        last_name_this_year[year] = last_name;
        birth_year = year;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birth_year){
            name_this_year[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= birth_year) {
            last_name_this_year[year] = last_name;
        }
    }
    string GetFullName(int year) const{
        if (year < birth_year) {
            return "No person";
        }
        else {
            string name_item = "None";
            string last_name_item = "None";
            for (auto &item: name_this_year) {

                if (item.first > year) {
                    break;
                }
                name_item = item.second;
            }
            for (auto &item: last_name_this_year) {

                if (item.first > year) {
                    break;
                }
                last_name_item = item.second;
            }
            if (name_item == "None" && last_name_item == "None") {
                return "Incognito";
            } else if (name_item == "None" && last_name_item != "None") {
                return last_name_item + " with unknown first name";
            } else if (name_item != "None" && last_name_item == "None") {
                return name_item + " with unknown last name";
            }
            return (name_item + " " + last_name_item);
        }
    }
    string GetFullNameWithHistory(int year) const{
        if (year < birth_year) {
            return "No person";
        }
        else {
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
                return history_last_names[history_last_names.size() - 1] + GetStringHistoryLast(history_last_names) +
                       " with unknown first name";
            } else if (history_names.size() > 0 && history_last_names.empty()) {
                return history_names[history_names.size() - 1] + GetStringHistory(history_names) +
                       "with unknown last name";
            } else if (history_names.size() > 0 && history_last_names.size() > 0) {
                return history_names[history_names.size() - 1] + GetStringHistory(history_names) +
                       history_last_names[history_last_names.size() - 1] + GetStringHistoryLast(history_last_names);
            }
        }
        return "";
    }
private:
    // приватные поля
    int birth_year;
    map<int, string> name_this_year;
    map<int, string> last_name_this_year;
};


int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}

