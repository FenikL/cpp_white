#include <iostream>
#include <numeric>
#include <cmath>
#include <sstream>

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
    return  (left.Numerator() == right.Numerator()) && (left.Denominator() == right.Denominator());
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
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
