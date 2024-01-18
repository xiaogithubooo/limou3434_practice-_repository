#include <iostream>
#include <boost/math/special_functions/factorials.hpp>
#include <boost/timer/timer.hpp>

int main()
{
    //������ʱ������
    boost::timer::auto_cpu_timer timer;

    //���������Ľ׳�
    double n = 170;
    double factorial_n = boost::math::factorial<double>(n);
    std::cout << n << "! = " << factorial_n << std::endl;

    //�����ʱ�����
    timer.report();

    return 0;
}