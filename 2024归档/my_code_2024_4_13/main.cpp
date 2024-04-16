//main.cpp

#include <memory>
#include "tcp_server.hpp"
#include "log.hpp"
#include "protocol.hpp"

static limou::Response CalculatorHelp(const limou::Request& req)
{
    limou::Response resp(0, 0);

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

void NetCal(limou::Connection* conn, std::string& request) //request 一定是完整的请求报文
{
    limou::Log log = limou::Log();
    log.LogMessage(DEBUG, "Processing business logic~~, %s %d", __FILE__, __LINE__);

    //反序列化
    limou::Request req;
    if (!req.Deserialize(request)) //反序列化失败
    {
        return; //相当于丢弃
    }

    //业务处理
    limou::Response resp = CalculatorHelp(req);

    //构建应答
    std::string sendstr = resp.Serialize(); //应答序列化
    sendstr = limou::Encode(sendstr); //添加分隔符

    //返回响应(上层用户不应该考虑怎么发送的问题)
    conn->_outbuffer += sendstr;

    //调用回指指针, 触发事件就绪, 否则一开始服务器没有关注写事件, 不会触发写回调
    conn->_tsvr->EnableReadWrite(conn, true, true);
}

int main(int argc, char const* argv[])
{
    std::unique_ptr<limou::TcpServer> svr(new limou::TcpServer());
    svr->Dispather(&NetCal); //上层用户指定对发送的完整报文的处理方法
    return 0;
}