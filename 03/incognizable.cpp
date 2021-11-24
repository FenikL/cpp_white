class Incognizable {
public:
    Incognizable() {};
    Incognizable(int a) {
        data1 = a;
    }
    Incognizable(int a, int b) {
        data1 = a;
        data2 = b;
    }

private:
    int data1;
    int data2;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}