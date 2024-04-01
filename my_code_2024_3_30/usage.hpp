/* 文件描述
存放用户的说明手册
*/

#pragma once

#include <iostream>
#include <string>

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}