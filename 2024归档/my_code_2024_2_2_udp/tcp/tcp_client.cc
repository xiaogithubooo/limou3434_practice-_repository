//tcp_client.cc
#include <iostream>
#include <string>

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
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(-1);
    }

    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    int sock = socket(
        AF_INET, //协议家族
        SOCK_STREAM, //通信类别
        0 //协议类别
    );

    //无需 bind

    

    return 0;
}