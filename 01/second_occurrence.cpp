#include <iostream>
#include <string>

using namespace std;

int main() {
    string f;
    int counter = -2;


    cin >> f;

    for (int i=0; i<f.size(); ++i){
        if (f[i] == 'f'){
            ++counter;
        }
        if (counter == 0) {
            counter = i;
            break;
        }
    }
    cout << counter;

    return 0;
}
