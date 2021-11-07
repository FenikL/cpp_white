#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d, x1, x2;
    cin >> a >> b >> c;

    if (a == 0 ) {
        if ( b != 0){
            cout << (-c / b);
            }
    } else {
        d = b*b - 4*a*c;
        if (d == 0) {
            cout << (-b/(2*a));
        }
        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2*a);
            x2 = (-b - sqrt(d)) / (2*a);
            cout << x1 << " " << x2;
        }
    }
    return 0;
}