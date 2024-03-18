//cal_server.cpp
#include <memory>
#include "tcp_server.hpp"

using namespace ns_tcpserver;

static void Usage(const std::string& proc)
{
    std::cout << "\nUsage: " << proc << " [ip(optional)] [port]\n" << std::endl;
}

void Debug(const int& sock)
{
    std::cout << "test" << sock << std::endl;
}

int main(int argc, char* argv[]) //服务器启动指令 ./udp_server ip port
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(-1);
    }

    std::unique_ptr<TcpServer> server(new TcpServer(atoi(argv[1])));
    server->BindServer(Debug);
    server->Start();

    return 0;
}
