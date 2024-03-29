//cal_client.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include "log.hpp"
#include "sock.hpp"
#include "protocol.hpp"

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

int main(int argc, char const* argv[])
{
    Log log = Log();

    if (argc != 3)
    {
        Usage(argv[0]);
        exit(5);
    }

    std::string server_ip = argv[1];
    uint16_t server_port = atoi(argv[2]);
    Sock sock;
    int sockfd = sock._Socket();
    sock._Connect(sockfd, server_ip, server_port);

    bool quit = false;
    while (!quit)
    {
        //1.获取需求
        std::cout << "Please Enter x, y, op: ";
        int x = 0;
        int y = 0;
        char op = 0;
        std::cin >> x >> y >> op;
        Request req(x, y, op); //制作请求

        //2.序列化
        std::string str = req.Serialize();

        //3.添加报头和标志位
        str = Encode(str);

        //4.发送请求
        Send(sockfd, str);

        //5.读取响应
        while (true)
        {
            std::string buffer;
            bool res = Recv(sockfd, &buffer);
            if (!res) //读取错误
            {
                quit = true;
                break;
            }

            std::string package = Decode(buffer);
            if (package.empty())
            {
                continue; //继续读取，直到读取到一个完整的数据包
            }

            //6.反序列化
            Response resp;
            resp.Deserialize(package);

            //7.检测结果是否异常
            std::string err;
            switch (resp._code)
            {
            case 1:
                err = "/0 error";
                break;
            case 2:
                err = "%0 error";
                break;
            case 3:
                err = "error";
                break;
            default:
                std::cout << "code: " << resp._code << " - result:" << resp._result << '\n';
                break;
            }

            if (!err.empty())
                std::cerr << err << std::endl;

            break;
        }
    }

    close(sockfd);
    return 0;
}
