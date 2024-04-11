#include <memory>
#include "tcp_server.hpp"

int main(int argc, char const* argv[])
{
    std::unique_ptr<limou::TcpServer> svr(new limou::TcpServer());
    return 0;
}
