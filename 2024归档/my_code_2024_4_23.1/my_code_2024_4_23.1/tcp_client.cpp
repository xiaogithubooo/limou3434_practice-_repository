//tcp_client.cpp(�̳߳ذ汾�ķ����)

#include <string>
#include <iostream>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include "log.hpp"

const int readBuffSize = 1024;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

int main(int argc, char* argv[]) //./udp_client 127.0.0.1 8080
{
    Log log = Log(); //���ڴ�ӡ��־����־����Ĭ������Ļ�����־������ debug �������Ϣ��

    //1.�������������
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(60);
    }

    //2.�����׽���
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) //����һ��С֪ʶ�㣺Ҳ���˰� AF_INET ���ɵȼ۵� PF_INET
    {
        log.LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        exit(70);
    }

    //3.���׽���
    //����һ�㲻��Ҫ����Ա�Լ� bind

    //4.�洢��Ҫ���ʷ���˵� ip �� port
    std::string serverIp = argv[1];
    uint16_t serverPort = atoi(argv[2]);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(serverIp.c_str());
    server.sin_port = htons(serverPort);

    //5.���ӷ����
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        log.LogMessage(FATAL, "connect() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        exit(80);
    }

    //6.�����˷�������
    while (true)
    {
        std::cout << "client >: ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "exit")
            break;

        send(sock, line.c_str(), line.size(), 0); //�����˷�������

        char readBuffer[readBuffSize] = { 0 };
        ssize_t s = recv(sock, readBuffer, sizeof(readBuffer) - 1, 0);
        if (s > 0)
        {
            std::cout << "server echo:> " << readBuffer << std::endl;
        }
        else if (s == 0) //�Զ˹ر�����
        {
            break;
        }
        else
        {
            log.LogMessage(FATAL, "recv() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        }
    }

    //7.�ر��׽���
    close(sock);
    log.LogMessage(NORMAL, "close udp client done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    std::cout << "bye~" << std::endl;

    return 0;
}