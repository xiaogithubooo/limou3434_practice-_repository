#include <iostream>
using namespace std;

class A {
public:
    /* virtual */ void func() { cout << "A::func1" << endl; }

public:
    int _a = 1;
};

int main() {
    A a;
    return 0;
}
