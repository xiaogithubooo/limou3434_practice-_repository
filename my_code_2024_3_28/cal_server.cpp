//cal_server.cpp
#include <signal.h>
#include "tcp_server.hpp"
#include "log.hpp"
#include "protocol.hpp"

//使用手册
static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

//具体计算逻辑
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
        //1.读取数据
        bool res = Recv(sock, &inbuffer); //读取消息的序列化请求
        if (!res) //这里只能证明读取成功
            break;

        std::cout << "inbuffer:" << inbuffer << std::endl; //debug

        //2.协议解析（保证得到完整的报文）
        std::string package = Decode(inbuffer); //(1)返回空的时候说明内部没有有效数据或者报文不完整
        if (package.empty())
        {
            continue; //继续读取
        }
        else //(2)否者就是可以使用的，已经有完整的数据报了
        {
            std::cout << "Decode:inbuffer:" << inbuffer << std::endl; //debug
            std::cout << "package:" << package << std::endl; //debug

            //3.序列化
            Request req;
            req.Deserialize(package); //要求请求做反序列化
            Response resp;
            resp = _CalculatorHelp(req); //将反序列化的结果拿去计算

            //4.反序列化
            std::string respString = resp.Serialize(); //把响应结果序列化
            std::cout << "respString:" << respString << std::endl; //debug

            //5.添加报头和标志位
            respString = Encode(respString);
            std::cout << "Encode:respString:" << respString << std::endl; //debug
            Send(sock, respString); //写回响应结果
            //TODU：但是这个发送也有一些问题，这里暂时不提，后续讲多路转接的时候再来修改
        }
    }
}

int main(int argc, char* argv[])
{
    //一般情况下 server 需要较为严谨的判断逻辑，通常都需要忽略 SIGPIPE 信号，防止运行中出现非法写入的问题（例如服务端写到一半时，客户端因为异常而被关闭）
    signal(SIGPIPE, SIG_IGN);

    Log log = Log();

    if (argc != 2)
    {
        Usage(argv[0]);       
        exit(4);
    }

    std::unique_ptr<TcpServer> server(new TcpServer(atoi(argv[1])));
    server->BindService(Calculator);
    server->Start();

    return 0;
}