//udp_client.cpp(Ⱥ���������)

#include <string>
#include <iostream>
#include <memory>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h> 
#include "log.hpp"
#include "thread.hpp"

const int readBuffSize = 1024;
std::string serverIp;
uint16_t serverPort = 0;
Log log;

//ʹ���ֲ�
static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

//�̷߳���: д����
static void UdpSend(int* psock)
{
    struct sockaddr_in server; //��Ӧ������׽�����Ϣ����
    bzero(&server, sizeof(server)); //����λ����
    server.sin_family = AF_INET; //����Э�����/��
    server.sin_addr.s_addr = inet_addr(serverIp.c_str()); //���� ip�����ֽڣ�, �ڲ������������裺(1)ת��Ϊ���ֽ� (2)��ת��Ϊ��������
    server.sin_port = htons(serverPort); //���� port�����ֽڣ�, ��������תΪ��������

    while (true)
    {
        std::string message;
        std::cerr << "clien >: "; //����ֻ������ cerr �����ض������, ��Ȼ��̫����, ������Ч
        std::getline(std::cin, message); //�û�������Ҫ���͵�����
        if (message == "exit")
            break;
        if (sendto(*psock, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server)) >= 0) //д��ɹ�
        {
            //LogMessage(NORMAL, "client write done... %s %d", __FILE__, __LINE__);
        }
        else //д��ʧ��
        {
            log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }
    }
}

//�̷߳���: ������
static void UdpRecv(int* psock)
{
    while (true)
    {
        char readBuff[readBuffSize] = { 0 }; //��һ�����������������ʱ, ����ϵͳ���� sendto() ִ�й��̳����Զ�Ϊ����˰�

        //ʵ���������Ѿ����˷���˵� ip �� port ����Ϣ��, ������ֻ��Ϊ��ռλ�͵��ù淶д��, �ڱ���Ŀ�п��Բ���ô������ʱ��ͻ��˿����������˵Ŀͻ��ˣ�
        struct sockaddr_in temp;
        bzero(&temp, sizeof(temp)); //����λ����
        socklen_t len = sizeof(temp);
        if (recvfrom(*psock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&temp, &len) >= 0)
        {
            std::cout << "server echo >: " << readBuff << std::endl;
        }
        else //��ȡʧ��
        {
            log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }
    }
}

int main(int argc, char* argv[]) //./udp_client 127.0.0.1 8080
{
    //1.�������������
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(-1);
    }

    //2.�����׽���
    int sock = socket(AF_INET, SOCK_DGRAM, 0); //�׽��ָ�Ϊȫ�ֱ���, ������̱߳�д����
    if (sock < 0) //����һ��С֪ʶ�㣺Ҳ���˰� AF_INET ���ɵȼ۵� PF_INET
    {
        log.LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        exit(-1);
    }

    //3.���׽���
    //��������ϵͳ�Զ� bind()

    //4.�洢��Ҫ���ʷ���˵� ip �� port
    serverIp = argv[1];
    serverPort = atoi(argv[2]);

    //5.����д�̺߳Ͷ��߳�
    std::unique_ptr<Thread<int*>> sender(new Thread<int*>("client_send_thread", UdpSend, &sock));
    std::unique_ptr<Thread<int*>> recver(new Thread<int*>("client_recv_thread", UdpRecv, &sock));

    //6.�����˷�����Ϣ�Ͷ�ȡ��Ϣ
    sender->Start();
    recver->Start();

    //TODO: �����е�С����: �ͻ���д�߳̽�����, ���ͻ��˶��߳�����ִ��һ����ѭ��, ���� Join() ��ʱ��ʹ�����̼߳�������
    
    //7.�����߳�
    sender->Join();
    recver->Join();

    //8.�ر��׽���
    close(sock);
    log.LogMessage(NORMAL, "close udp client done ... %s %d", __FILE__, __LINE__);
    std::cout << "bye~" << std::endl;

    return 0;
}