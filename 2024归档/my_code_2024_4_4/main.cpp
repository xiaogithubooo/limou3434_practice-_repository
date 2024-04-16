#include <iostream>
#include <string>
#include <unistd.h>
#include "sock.hpp"
int main()
{
    Sock sock;
    int listen = sock._Socket();
    sock._Bind(listen, 8080);
    sock._Listen(listen);

    while (true)
    {
        std::string client_ip;
        uint16_t client_port;
        int sockfd = sock._Accept(listen, &client_ip, &client_port);
        if (sockfd > 0)
        {
            std::cout << "[" << client_ip << ":" << client_port << "]echo >" << sockfd;
        }
    }

    return 0;
}