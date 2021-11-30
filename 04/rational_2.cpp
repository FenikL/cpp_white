#include <iostream>
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
        if ((new_denominator * new_numerator) < 0) {
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

Rational operator+(const Rational& left, const Rational& right) {
    return Rational(left.Numerator()*right.Denominator() + right.Numerator()*left.Denominator(),
                    left.Denominator() * right.Denominator());
}

Rational operator-(const Rational& left, const Rational& right) {
    return Rational(left.Numerator()*right.Denominator() - right.Numerator()*left.Denominator(),
                    left.Denominator() * right.Denominator());
}

bool operator==(const Rational& left, const Rational& right) {
    return  (left.Numerator() == right.Numerator()) && (left.Denominator()==right.Denominator());
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
