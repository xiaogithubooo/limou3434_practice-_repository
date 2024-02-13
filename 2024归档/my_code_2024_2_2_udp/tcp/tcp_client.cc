//tcp_client.cc
#include <iostream>
#include <string>

#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

static void Usage(std::string proc)
{
    std::cout << "\nUsage:" << proc << "serverIp serverProt\n" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(-1);
    }

    std::string serverIp = argv[1];
    uint16_t serverPort = atoi(argv[2]);

    int sock = socket(
        AF_INET, //协议家族
        SOCK_STREAM, //通信类别
        0 //协议类别
    );

    //无需 bind，让 OS 自己选择，在 connect() 链接服务器中会自动绑定
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverPort);
    server.sin_addr.s_addr = inet_addr(serverIp.c_str());
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) //链接客户端
    {
        std::cerr << "connect error" << std::endl;
        exit(-1);
    }

    std::cout << "connect success" << std::endl;

    while (true)
    {
        std::string line;
        std::cout << "insert>:";
        std::getline(std::cin, line);
        send(sock, line.c_str(), line.size(), 0); //类似 write()，send() 专门给 TCP 来用，send_to() 专门给 UDP 来用，最后一个参数一般是 0

        char buffer[1024] = { 0 };
        ssize_t s = recv(sock, buffer, sizeof(buffer) - 1, 0); //类似 read()，读取服务器的返回值
        if (s > 0)
        {
            std::cout << "server 回显" << buffer << std::endl;
        }
        else //对端关闭链接或者读取失败
        {
            break;
        }
    }

    close(sock);

    return 0;
}