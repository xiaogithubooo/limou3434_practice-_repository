//protocol.hpp
/* 文件描述
主要是对协议的定制，该协议是我们自己定义的
*/

#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>

#define SPACE " "
#define SPACE_LEN strlen(SPACE) //这么做是为了可拓展
#define SEP "\r\n"
#define SEP_LEN strlen(SEP)

//定制协议

//1.请求的序列化和反序列化
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

//2.响应的序列化和反序列化
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
    char buffer[1024] = { 0 };
    ssize_t s = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (s > 0)
    {
        *out += buffer;
    }
    else if (s == 0) //对端关闭了
    {
        std::cout << "clienr quit..." << std::endl;
        return false;
    }
    else
    {
        std::cout << "send error..." << std::endl;
        return false;
    }
    return true;
}
//发送数据报
void Send(int sock, const std::string str)
{
    std::cout << "Send quit..." << std::endl;
    send(sock, str.c_str(), str.size(), 0);
}

//提取完整有效载荷
std::string Decode(std::string& buffer)
{
    //length\r\n123 + 456\r\n
    //长度还没有读取完毕，返回空串继续读取，直到下次一次能遇到 '\r\n' 标识符
    std::size_t pos = buffer.find(SEP);
    if (pos == std::string::npos)
    {
        return "";
    }

    //走到这里说明一定可以获取到长度，若 surplus 和报头的长度 length 一样，说明足够返回一个完整的数据报
    int length = atoi(buffer.substr(0, pos).c_str());
    int surplus = buffer.size() - pos - SEP_LEN - SEP_LEN; //有效载荷的字符长度
    if (surplus >= length) //则说明至少存在一个完整的数据报，可以进行提取
    {
        buffer.erase(0, pos + SEP_LEN); //移走前面的长度和标识符
        std::string data = buffer.substr(0, length); //截取拷贝有效载荷
        buffer.erase(0, length + SEP_LEN); //移走已经被拷贝的数据和标识符
        return data;
    }
    else //虽然获取到了长度，但是数据还不够凑成一个完整的数据报
    {
        return "";
    }
}

//添加报头和标志符
std::string Encode(const std::string& str)
{
    std::string length = std::to_string(str.size());
    std::string new_package = length;
    new_package += SEP;
    new_package += str;
    new_package += SEP;
    return new_package;
}

//约定就体现在、结构化的数据上、序列解析顺序上、运算结果的状态码