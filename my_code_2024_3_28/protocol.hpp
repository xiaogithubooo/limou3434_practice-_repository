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
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include "log.hpp"

#define SPACE " "
#define SPACE_LEN strlen(SPACE) //这么做是为了可拓展
#define SEP "\r\n"
#define SEP_LEN strlen(SEP) //这么做是为了可拓展

//请求中有效载荷的“序列化”和“反序列化”（客户端序列化请求，服务端反序列化请求）
class Request
{
public:
    Request() {}
    Request(int x, int y, char op) : _x(x), _y(y), _op(op) {}

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
        _op = str[left + SPACE_LEN];
        _y = atoi(str.substr(right + SPACE_LEN).c_str());

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


//读取数据报
bool Recv(int sock, std::string* out)
{
    Log log;

    char buffer[1024] = { 0 };
    ssize_t str = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (str > 0)
    {
        *out += buffer;
        return true;
    }
    else if (str == 0) //对端关闭了
    {
        log.LogMessage(WARNING, "clienr quit... %s %d", __FILE__, __LINE__);
        return false;
    }
    else
    {
        log.LogMessage(FATAL, "recv() error %s %d", __FILE__, __LINE__);
        return false;
    }
}

//发送数据报
void Send(int sock, const std::string str)
{
    send(sock, str.c_str(), str.size(), 0);
}


//提取完整有效载荷
std::string Decode(std::string& buffer)
{
    //length\r\n123 + 456\r\n

    //长度信息还没有读取完毕，返回空串继续读取，直到下次一次能遇到 '\r\n' 标识符
    std::size_t pos = buffer.find(SEP);
    if (pos == std::string::npos)
    {
        return "";
    }

    //走到这里说明一定可以获取到长度，若剩余的大小 surplus >= 报头的长度 length，说明足够返回至少一个完整数据报
    int length = atoi(buffer.substr(0, pos).c_str());
    int surplus = buffer.size() - pos - SEP_LEN - SEP_LEN; //除去标志符后剩余的字符长度
    if (surplus < length) //虽然获取到了长度信息，但是数据还不够凑成一个完整的数据报
    {
        return "";
    }
    else //surplus >= 报头的长度 length，则说明至少存在一个完整的数据报，可以进行提取并且返回
    {
        buffer.erase(0, pos + SEP_LEN); //移走前面的长度信息和标识符（虽然暴力，不过我们的重点不在效率）
        std::string data = buffer.substr(0, length); //拷贝需要的有效载荷信息
        buffer.erase(0, length + SEP_LEN); //移走已经被拷贝的数据和后面的标识符
        return data;
    }
    
}

//添加报头和标志符
std::string Encode(const std::string& str)
{
    std::string length = std::to_string(str.size());
    std::string new_package = length;
    new_package += SEP; //这个 SEP 标识符是为了分割长度信息和有效载荷，区别两者
    new_package += str;
    new_package += SEP; //这个 SEP 标识符更多是为了打印时方便一点
    return new_package;
}