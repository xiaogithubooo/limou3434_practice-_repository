#include <iostream>
#include <memory>
#include <cassert>
#include "http_server.hpp"
#include "usage.hpp"

void HandlerHttpRequest(int sockfd)
{
    //1.读取请求
    char buffer[1024] = { 0 };
    ssize_t s = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (s > 0)
    {
        buffer[s] = 0;
        std::cout << buffer << "---------------\n" << std::endl;
    }

    //2.返回响应
    std::string httpResponse = "HTTP/1.1 200 OK\r\n"; //状态行
    httpResponse += "\r\n"; //暂时不写响应报头，直接添加空行（现代的浏览器大部分都可以补充上报头的属性，依旧可以进行自定义识别）
    httpResponse += "<p>I am limou.</p>"; //暂时不写响应报头，直接添加空行（现代的浏览器大部分都可以补充上报头的属性，依旧可以进行自定义识别）
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