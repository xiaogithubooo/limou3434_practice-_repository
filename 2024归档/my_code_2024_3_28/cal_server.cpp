//cal_server.cpp(自定义协议)
#include <signal.h>
#include <cstdio>
#include "tcp_server.hpp"
#include "protocol.hpp"
#include "daemon.hpp"

//使用手册
static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

//线程的调用方法
static Response _CalculatorHelp(const Request& req)
{
    Response resp(0, 0);
    switch (req._op)
    {
    case '+':
        resp._result = req._x + req._y;
        break;

    case '-':
        resp._result = req._x - req._y;
        break;

    case '*':
        resp._result = req._x * req._y;
        break;

    case '/':
        if (req._y == 0)
            resp._code = 1;
        else
            resp._result = req._x / req._y;
        break;

    case '%':
        if (req._y == 0)
            resp._code = 2;
        else
            resp._result = req._x % req._y;
        break;

    default:
        resp._code = 3;
        break;
    }

    return resp;
}
void Calculator(int sock)
{
    std::string inbuffer;
    while (true)
    {
        //1.读取从客户端发送的、序列化后的请求
        bool result = Recv(sock, &inbuffer);
        if (!result) //通过这里的 if 语句也只能证明读取成功，不能保证数据的完整性
            break;

        std::cout << "inbuffer:" << inbuffer << std::endl; //[debug]

        //2.保证得到完整的响应数据
        std::string package = Decode(inbuffer); //(1)返回空的时候说明内部没有有效数据或者报文不完整
        if (package.empty())
        {
            continue; //继续循环读取，直到 package 不为空
        }
        else //(2)否者就是可以使用的，已经有完整的数据报了
        {
            std::cout << "Decode:inbuffer:" << inbuffer << std::endl; //[[debug]]
            std::cout << "package:" << package << std::endl; //[debug]

            //3.反序列化请求，拿数据去计算后返回给请求结构体对象
            Request req;
            req.Deserialize(package); 
            Response resp;
            resp = _CalculatorHelp(req); //将反序列化的结果拿去计算

            //4.序列化响应，并且加上报头发送给客户端
            std::string respString = resp.Serialize(); //把响应结果序列化
            std::cout << "respString:" << respString << std::endl; //[debug]

            respString = Encode(respString);
            std::cout << "Encode:respString:" << respString << std::endl; //[debug]

            Send(sock, respString); //写回响应结果
            //TODU：但是这个发送也有一些问题，这里暂时不提，后续讲多路转接的时候再来修改
        }
    }
}

int main(int argc, char* argv[]) //使用 ./cal_server 8080 来启动服务端
{
    if (argc != 2)
    {
        Usage(argv[0]);       
        exit(4);
    }

    MyDaemon(); //调用后，父进程的部分退出，内部创建的子进程变成守护进程，后续可以使用 ps -axj | grep cal_server 来查看（可以观察到 PPID:1 ，这说明守护进程就是一种孤儿进程）
    printf("dimou");
    //以下步骤都开始由子进程进行操作，注意日志消息需要写入到文件中，而不能直接输出（为方便修改，我直接把之前写的日志类构造函数中的 writeMode 默认为 ONE_FILE），并且需要把所有的标准 IO 输出都会被重定向到 /dev/null 中
    std::unique_ptr<TcpServer> server(new TcpServer(atoi(argv[1])));
    server->BindService(Calculator); //在任务列表中绑定一些任务
    server->Start(); //启动服务器

    return 0;
}