#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
    explicit Student (string& new_first_name, string& new_last_name, int new_day, int new_month, int new_year) {
        first_name = new_first_name;
        last_name = new_last_name;
        day = new_day;
        month = new_month;
        year = new_year;
    }
};

int main() {
    int N;
    cin >> N;
    vector<Student> students;
    for (int i =0; i < N; ++i) {
        string first_name;
        string last_name;
        int day;
        int month;
        int year;
        cin >> first_name >> last_name >> day >> month >> year;
        Student student(first_name, last_name, day, month, year);
        students.push_back(student);
    }
    int M;
    cin >> M;
    for (int j = 0; j < M; ++j) {
        string command;
        int k;
        cin >> command >> k;
        if (command == "name" && k > 0 && k <= N) {
            cout << students[k-1].first_name << " " << students[k-1].last_name;
        }
        else if (command == "date" && k > 0 && k <= N) {
            cout << students[k-1].day << "." << students[k-1].month << "." << students[k-1].year;
        }
        else {
            cout << "bad request";
        }
        cout << endl;
    }
    return 0;
}
