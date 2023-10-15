#include "function.hpp"

template <typename T>
void MyFunction(T value)
{
    cout << value << endl;
}
//显式实例化int类型的函数模板
template void MyFunction<int>(int value);
