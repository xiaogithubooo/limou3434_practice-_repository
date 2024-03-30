//cal_client.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include "log.hpp"
#include "sock.hpp"
#include "protocol.hpp"

//使用手册
static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

int main(int argc, char const* argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(5);
    }

    Log log = Log();
    Sock sock; //套接字工具包
    
    std::string server_ip = argv[1];
    uint16_t server_port = atoi(argv[2]);
    int sockfd = sock._Socket();
    sock._Connect(sockfd, server_ip, server_port); //连接服务端

    bool quit = false;
    while (!quit)
    {
        //1.获取需求
        std::cout << "Please Enter x, y, op: ";
        int x = 0;
        int y = 0;
        char op = 0;
        std::cin >> x >> y >> op;

        //2.制作请求并且进行序列化
        Request req(x, y, op);
        std::string result = req.Serialize();

        //3.添加报头和标志位再发送请求
        result = Encode(result);
        Send(sockfd, result);

        //4.读取响应并做处理
        while (true)
        {
            std::string buffer;
            bool res = Recv(sockfd, &buffer);
            if (!res) //通过这个 if 语句只能说明读取没有出错
            {
                quit = true;
                break;
            }

            std::string package = Decode(buffer); //尝试获取完整的数据包
            if (package.empty())
            {
                continue; //继续读取，直到读取到一个完整的数据包
            }

            //5.把完整的响应做反序列化
            Response resp;
            resp.Deserialize(package);

            //6.检测结果是否出现异常
            std::string err;
            switch (resp._code)
            {
            case 0:
                //让 err 继续保持空即可
                break;
            case 1:
                err = "/0 error";
                break;
            case 2:
                err = "%0 error";
                break;
            case 3:
                err = "other error";
                break;
            default:
                break;
            }

            if (err.empty()) //为空
            {
                std::cout << "code: " << resp._code << " - result:" << resp._result << '\n';
            }
            else
            {
                std::cerr << err << std::endl;
            }

            break;
        }
    }

    close(sockfd); //客户端结束后最好还是关闭套接字标识符
    return 0;
}
