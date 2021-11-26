#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
     fstream input("/home/user/CLionProjects/cpp_white/04/input.txt");
     int N;
     int M;
     input >> N >> M;
     input.ignore(1);
     vector<string> values(M);
     for (int i = 0; i < M; ++i) {

     }
     input.ignore(1);

     for (const string& s : values) {
         cout << s << " " << endl;
     }
    return 0;
}