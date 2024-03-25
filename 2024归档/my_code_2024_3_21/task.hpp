//task.hpp(线程池)

/* 使用方法
Task t = Task(操作数1, 操作数2, 操作符);
t.Run(); 或 仿函数 t(); 来调用执行任务，并且返回结果
t.Show(); 查看任务的具体内容
*/

#pragma once

const int gDefaultResult = 0;
enum
{
    OK = 0, //正常执行
    DIVISION_ZERO = 1, //除零错误
    MODULO_ZERO = 2, //模零错误
    UNKONW = 3, //未知错误
};

class Task
{
public:
    Task() {}

    Task(const int& x, const int& y, const char& op)
        : _data_x(x), _data_y(y), _oper(op), _result(gDefaultResult), _code(OK)
    {}

    int Run()
    {
        switch (_oper)
        {
        case '+':
            _result = _data_x + _data_y;
            break;

        case '-':
            _result = _data_x - _data_y;
            break;

        case '*':
            _result = _data_x * _data_y;
            break;

        case '/':
            if (_data_y == 0)
            {
                _code = UNKONW;
            }
            else
            {
                _result = _data_x / _data_y;
            }
            break;

        case '%':
            if (_data_y == 0)
            {
                _code = UNKONW;
            }
            else
            {
                _result = _data_x % _data_y;
            }
            break;

        default:
            _code = UNKONW;
            break;
        }
        return _result;
    }

    int operator()()
    {
        return Run();
    }

    std::string Show()
    {
        std::string ret;
        ret += std::to_string(_data_x);
        ret += _oper;
        ret += std::to_string(_data_y);
        return ret;
    }

    void Status()
    {
        std::cout << "status code:" << _code << std::endl;
    }

private:
    int _data_x;
    int _data_y;
    char _oper;
    int _result; //返回值
    int _code; //为 0 则为结果可信任，非 0 表示结果不可信
};
