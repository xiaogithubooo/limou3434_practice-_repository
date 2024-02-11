//tcp_server.cc
#include "tcp_server.hpp"
#include <memory>

static void Usage(std::string proc)
{
    std::cout << "\nUsage:" << proc << " prot\n" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
    }

    uint16_t port = atoi(argv[1]);
    std::unique_ptr<TcpServer> svr(new TcpServer(port));
    svr->Start();

    return 0;
}