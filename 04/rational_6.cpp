#include <iostream>
#include <exception>
#include <numeric>
using namespace std;

void EnsureNotNull(int denominator) {
    if (denominator == 0) {
        throw invalid_argument("denominator = 0");
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        EnsureNotNull(new_denominator);
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

private:
    int numerator;
    int denominator;
};

Rational operator/(const Rational& left, const Rational& right) {
    if (right.Numerator() == 0) {
        throw domain_error("");
    }
    return Rational(left.Numerator() * right.Denominator(),
                    left.Denominator() * right.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}

