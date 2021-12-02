#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        if (new_month > 0 && new_month < 13) {
            month = new_month;
        } else {
            throw month;
        }
        if (new_day > 0 && new_day < 32) {
            day = new_day;
        } else {
            throw day;
        }
    }
    int GetYear() const {
      return year;
    }
    int GetMonth() const {
      return month;
    }
    int GetDay() const {
      return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth()) {
        return lhs.GetDay() < rhs.GetDay();
    } else if (lhs.GetYear() == rhs.GetYear()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

/*bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.GetYear() == rhs.GetYear() &&
            lhs.GetMonth() == rhs.GetMonth() &&
            lhs.GetDay() == rhs.GetDay());
}
 */

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << "-"
    << setw(2) << date.GetMonth() << "-"
    << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event)
  {
      events_in_year[date].insert(event);
  }
  void DeleteEvent(const Date& date, const string& event) {
      if (events_in_year.count(date) == 0) {
          cout << "Event not found";
      } else if (events_in_year[date].count(event) == 0) {
          cout << "Event not found";
      } else {
          events_in_year[date].erase(event);
          cout << "Deleted successfully";
      }
      cout << endl;
  }
  void  DeleteDate(const Date& date) {
      int N = events_in_year.count(date);
      if (N != 0) {
          events_in_year.erase(date);
      }
      cout << "Deleted " << N << " events" << endl;
  }

  void Find(const Date& date) {
      if (events_in_year.count(date) != 0) {
          for (const string& event : events_in_year[date]) {
              cout << event << endl;
          }
      }
  }
  
  void Print() {
      for (auto& item : events_in_year) {
          for (const string& event : events_in_year[item.first]) {
              cout << item.first << " " << event << endl;
          }
      }
  }

private:
    map<Date, set<string>> events_in_year;
};

class Command {
public:
    Command(const string& new_request, const string& new_date, const string& new_event) {
        request = new_request;
        date = new_date;
        event = new_event;
    }
    string GetRequest() {
        return request;
    }
    string GetDate() {
        return date;
    }
    string GetEvent() {
        return event;
    }
private:
    string request;
    string date;
    string event;
};

Command ParseCommand(const string& new_command) {
    stringstream stream(new_command);
    string request;
    string date;
    string event;
    stream >> request >> date >> event;
    return Command(request, date, event);
}

void EnsureNextSymbolAndSkip(stringstream& stream, const string& date) {
    if (stream.peek() != '-') {
        throw date;
    }
    stream.ignore(1);
    if (stream.peek() != '-' &&
        stream.peek() != '0' &&
        stream.peek() != '1' &&
        stream.peek() != '2' &&
        stream.peek() != '3' &&
        stream.peek() != '4' &&
        stream.peek() != '5' &&
        stream.peek() != '6' &&
        stream.peek() != '7' &&
        stream.peek() != '8' &&
        stream.peek() != '9'){
        throw date;
    }
    stream.get();
    if (stream.peek() != '0' &&
        stream.peek() != '1' &&
        stream.peek() != '2' &&
        stream.peek() != '3' &&
        stream.peek() != '4' &&
        stream.peek() != '5' &&
        stream.peek() != '6' &&
        stream.peek() != '7' &&
        stream.peek() != '8' &&
        stream.peek() != '9') {
        throw date;
    }
    stream.unget();
}

Date ParseDate(const string& date) {
    stringstream stream(date);
    int year;
    int month;
    int day;
    stream >> year;
    EnsureNextSymbolAndSkip(stream, date);
    stream >> month;
    EnsureNextSymbolAndSkip(stream, date);
    stream >> day;
    return Date(year, month, day);
}

int main() {

  Database db;
    
  string command;
  while (getline(cin, command)) {
      Command parsed_command = ParseCommand(command);
      if (parsed_command.GetRequest() == "Add") {
          Date parsed_date = ParseDate(parsed_command.GetDate());
          db.AddEvent(parsed_date, parsed_command.GetEvent());
      } else if (parsed_command.GetRequest() == "Del" && !parsed_command.GetEvent().empty()) {
          Date parsed_date = ParseDate(parsed_command.GetDate());
          db.DeleteEvent(parsed_date, parsed_command.GetEvent());
      } else if (parsed_command.GetRequest() == "Del" && parsed_command.GetEvent().empty()) {
          Date parsed_date = ParseDate(parsed_command.GetDate());
          db.DeleteDate(parsed_date);
      } else if (parsed_command.GetRequest() == "Find") {
          Date parsed_date = ParseDate(parsed_command.GetDate());
          db.Find(parsed_date);
      } else if (parsed_command.GetRequest() == "Print") {
          db.Print();
      } else {
          throw parsed_command.GetRequest();
      }
  }

  return 0;
}