//http_server.cpp
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <cassert>
#include "http_server.hpp"
#include "usage.hpp"
#include "util.hpp"

#define ROOT "./wwwroot"
#define HOMW_PAGE "index.html"

void HandlerHttpRequest(int sockfd)
{
    //1.读取请求
    char buffer[1024] = { 0 };
    ssize_t s = recv(sockfd, buffer, sizeof(buffer) - 1, 0);

    //2.分割请求信息
    std::vector<std::string> vline;
    Util::_CutString(buffer, "\n", &vline);

    for (auto& it : vline)
        std::cout << "---" << it << std::endl;

    std::vector<std::string> vblock;
    Util::_CutString(vline[0], " ", &vblock);

    //3.获取资源
    std::string target = ROOT; //"./wwwroot"
    std::string file = vblock[1];

    if (file == "/")
        file = "/index.html";

    target += file; //"./wwwroot/index.html"
    
    std::cout << "***" << target << "***" << "\n\n";

    std::string content;
    std::ifstream in(target);
    if (in.is_open())
    {
        std::string line;
        while (std::getline(in, line))
        {
            content += line;
        }
    }
    in.close();

    //2.返回响应
    std::string httpResponse;
    if (content.empty()) //资源不存在的话
    {
        httpResponse = "HTTP/1.1 302 FOUND\r\n"; //状态行
        httpResponse += "Location: https://blog.csdn.net/m0_73168361?spm=1000.2115.3001.5343"; //重定向到我的 CSDN 博客
    }
    else
    {
        httpResponse = "HTTP/1.1 200 OK\r\n"; //状态行
        httpResponse += "Content-Type: text/html\r\n"; //状态行(支持文本和html)
        httpResponse += "Content-Length: " + std::to_string(content.size()) + "\r\n"; //状态行(添加正文长度)
        httpResponse += "Set-Cookie: This is a cookie.\r\n"; //状态行(设置 cookie)
    }
    httpResponse += "\r\n"; //暂时不写响应报头，直接添加空行（现代的浏览器大部分都可以补充上报头的属性，依旧可以进行自定义识别）
    httpResponse += content; //暂时不写响应报头，直接添加空行（现代的浏览器大部分都可以补充上报头的属性，依旧可以进行自定义识别）
    send(sockfd, httpResponse.c_str(), httpResponse.size(), 0);
}

int main(int argc, char const* argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(-1);
    }

    std::unique_ptr<HttpServer> hs(new HttpServer(atoi(argv[1]), HandlerHttpRequest));
    hs->Start();
    
    return 0;
}