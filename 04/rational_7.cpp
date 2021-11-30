#include <iostream>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;

    if (is) {
        is >> n >> c >> d;
        if (is) {
            if (c == '/') {
                r = Rational(n, d);
            }
            else {
                is.setstate(ios_base::failbit);
            }
        }
    }

    return is;
}

ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}

int main() {
    try {
        Rational r1;
        Rational r2;
        char opr;
        cin >> r1 >> opr >> r2;
        if (opr == '*') {
            cout << r1*r2;
        } else if (opr == '/') {
            cout << r1/r2;
        } else if (opr == '+') {
            cout << r1 + r2;
        } else {
            cout << r1 - r2;
        }
    } catch (invalid_argument& ex_invalid) {
        cout << ex_invalid.what() << endl;
    } catch (domain_error& ex_do) {
        cout << ex_do.what() << endl;
    }
    return 0;
}