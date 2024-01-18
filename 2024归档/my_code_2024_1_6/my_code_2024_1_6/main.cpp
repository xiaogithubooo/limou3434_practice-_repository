#include <iostream>
#include <boost/math/special_functions/factorials.hpp>
#include <boost/timer/timer.hpp>

int main()
{
    //创建计时器对象
    boost::timer::auto_cpu_timer timer;

    //计算整数的阶乘
    double n = 170;
    double factorial_n = boost::math::factorial<double>(n);
    std::cout << n << "! = " << factorial_n << std::endl;

    //输出计时器结果
    timer.report();

    return 0;
}