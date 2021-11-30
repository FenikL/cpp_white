#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        int gcd_rational = gcd(new_numerator, new_denominator);
        if ((new_denominator < 0) || (new_numerator < 0)) {
            numerator = -abs(new_numerator) / gcd_rational;
            denominator = abs(new_denominator) / gcd_rational;
        } else if ((new_denominator * new_numerator) == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            numerator = abs(new_numerator) / gcd_rational;
            denominator = abs(new_denominator) / gcd_rational;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }
    int numerator;
    int denominator;
};

Rational operator+(const Rational& left, const Rational& right) {
    return Rational(left.Numerator()*right.Denominator() + right.Numerator()*left.Denominator(),
                    left.Denominator() * right.Denominator());
}

Rational operator-(const Rational& left, const Rational& right) {
    return Rational(left.Numerator()*right.Denominator() - right.Numerator()*left.Denominator(),
                    left.Denominator() * right.Denominator());
}

Rational operator*(const Rational& left, const Rational& right) {
    return Rational(left.Numerator() * right.Numerator(),
                    left.Denominator() * right.Denominator());
}

Rational operator/(const Rational& left, const Rational& right) {
    return Rational(left.Numerator() * right.Denominator(),
                    left.Denominator() * right.Numerator());
}

bool operator==(const Rational& left, const Rational& right) {
    return  (left.Numerator() == right.Numerator()) && (left.Denominator()==right.Denominator());
}

bool operator<(const Rational& left, const Rational& right) {
    return ((double)left.Numerator() / left.Denominator()) < ((double)right.Numerator() / right.Denominator());
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int numerator = rational.Numerator();
    int denominator = rational.Denominator();
    char c = '/';
    stream >> numerator;
    rational = Rational();
    stream >> c;
    stream >> denominator;
    if (c != '/' || denominator == rational.Denominator()) {
        rational = Rational();
    } else {
        rational = Rational(numerator, denominator);
    }
    return stream;
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
