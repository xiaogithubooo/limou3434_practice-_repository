#include <iostream>
using namespace std;
class Data
{
public:
    Data(int a = 1, int b = 1)
    :_a(a)
    ,_b(b)
    {
        cout << "Data(int a, int b)" << endl;
    }
    void Print(void)
    {
        cout << _a << " " << _b << endl;
    }
private:
    int _a;
    int _b;
};
int main()
{
    Data().Print();
    return 0;
}
