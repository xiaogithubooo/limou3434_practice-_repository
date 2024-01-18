#include <iostream>
using namespace std;
namespace limou
{
    class Data
    {
    public:
        Data(int data1 = 1, int data2 = 2, int data3 = 3)
            : _data1(data1), _data2(data2), _data3(data3)
        {}
        void print()
        {
            cout << _data1 << endl;
            cout << _data2 << endl;
            cout << _data3 << endl;
        }
    private:
        int _data1;
        int _data2;
        int _data3;
    };
}
int main()
{
    limou::Data d;
    d.print();
    return 0;
}

