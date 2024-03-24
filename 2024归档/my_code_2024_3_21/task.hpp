//task.hpp(多线程版本)
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
    public:Task()
    {}

    public:Task(const int& x, const int& y, const char& op)
        : _data_x(x), _data_y(y), _oper(op), _result(gDefaultResult), _code(OK)
    {}

    public:int Run()
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

    public:int operator()()
    {
        return Run();
    }

    public:std::string Show()
    {
        std::string ret;
        ret += std::to_string(_data_x);
        ret += _oper;
        ret += std::to_string(_data_y);
        return ret;
    }

    public:void Status()
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
