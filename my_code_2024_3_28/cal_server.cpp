//cal_server.cpp
#include "tcp_server.hpp"
#include "log.hpp"

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

void debug(int sock)
{
    std::cout << "---" << sock << "---" << std::endl;
}

int main(int argc, char* argv[])
{
    Log log = Log();

    if (argc != 2)
    {
        Usage(argv[0]);       
        exit(4);
    }

    std::unique_ptr<TcpServer> server(new TcpServer(atoi(argv[1])));
    server->BindService(debug);
    server->Start();

    return 0;
}