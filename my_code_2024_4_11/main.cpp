//main.cpp
#include <memory>
#include "poll_server.hpp"

int main()
{
    std::unique_ptr<PollServer> svr(new PollServer());
    svr->Start();
    return 0;
}