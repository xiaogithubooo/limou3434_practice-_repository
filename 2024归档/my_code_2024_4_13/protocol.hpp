//protocol.hpp

/* 文件描述
主要是对协议的定制，该协议是自定义的，是对协议的模拟
其中约定就体现在：
(1) 结构化的数据
(2) 序列和反序列化的解析顺序
(3) 运算结果的状态码
(4) 报头的封装规定
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include "log.hpp"

namespace limou
{
#define SPACE " "
#define SPACE_LEN strlen(SPACE) //这么做是为了可拓展
#define SEP "X"
#define SEP_LEN strlen(SEP) //这么做是为了可拓展

    //请求中有效载荷的“序列化”和“反序列化”（客户端序列化请求，服务端反序列化请求）
    class Request
    {
    public:
        Request() {}

        Request(int x, int y, char op): _x(x), _y(y), _op(op) {}

        //序列化为 "_x _op _y"
        std::string Serialize()
        {
            std::string str;
            str += std::to_string(_x);
            str += SPACE;
            str += _op;
            str += SPACE;
            str += std::to_string(_y);
            return str;
        }

        //反序列化为 { int _x; int _y; char _op; }
        bool Deserialize(const std::string& str)
        {
            std::size_t left = str.find(SPACE);
            if (left == std::string::npos)
                return false;

            std::size_t right = str.rfind(SPACE);
            if (right == std::string::npos)
                return false;

            _x = atoi(str.substr(0, left).c_str());
            _y = atoi(str.substr(right + SPACE_LEN).c_str());
            //_op = str[left + SPACE_LEN];
            if (left + SPACE_LEN > str.size())
            {
                return false;
            }
            else
            {
                _op = str[left + SPACE_LEN];
            }

            return true;
        }

    public:
        int _x; //操作数
        int _y; //操作数
        char _op; //操作符
    };

    //响应中有效载荷的“序列化”和“反序列化”（服务端序列化响应，客户端反序列化请求）
    class Response
    {
    public:
        Response() {}

        Response(int result, int code) : _result(result), _code(code) {}

        //序列化为 "_code _result"
        std::string Serialize()
        {
            std::string str;
            str += std::to_string(_code);
            str += SPACE;
            str += std::to_string(_result);
            return str;
        }

        //反序列化为 { int _result; int _code; }
        bool Deserialize(const std::string& str)
        {
            std::size_t pos = str.find(SPACE);
            if (pos == std::string::npos)
                return false;

            _code = atoi(str.substr(0, pos).c_str());
            _result = atoi(str.substr(pos + SPACE_LEN).c_str());
            
            return true;
        }

    public:
        int _result; //计算结果
        int _code; //计算状态码
    };

    //分割 buffer(100+99X200-34X...) 报文放入 out 列表中
    void SpliteMessage(std::string& buffer, std::vector<std::string>* out)
    {
        while (true)
        {
            auto pos = buffer.find(SEP);
            if (std::string::npos == pos) //直到找不到"X", 注意最后剩余的字符串会等下一次完整了再进行分割
            {
                break;
            }
            std::string message = buffer.substr(0, pos);
            buffer.erase(0, pos + SEP_LEN); //移走已经被读取的报文
            //TODO: 这里可以稍微提高一下效率
            out->push_back(message);
            std::cout << message << '\n';
            sleep(1);
        }
    }

    //添加不同报文之间的分隔符
    std::string Encode(const std::string& str)
    {
        return str + SEP;
    }
}