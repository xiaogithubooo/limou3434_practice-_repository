//main.cpp
#include <memory>
#include <memory>
#include "epoll_server.hpp"

void Change(std::string request) //服务端可以保证是完整请求
{
    //业务请求, 这里只是简单的让客户端的请求打印即可
    std::cout << "处理业务:" << request << std::endl;
}

int main()
{
    std::unique_ptr<EpollServer> svr(new EpollServer(Change));
    svr->Start();
    return 0;
}