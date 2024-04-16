//main.cpp
#include <memory>
#include "select_server.hpp"

int main()
{
    std::unique_ptr<SelectServer> svr(new SelectServer());
    svr->Start();
    return 0;
}