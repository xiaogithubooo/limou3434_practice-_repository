//udp_client.cpp(Զ�̲�������)
#include <string>
#include <iostream>
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
    Log log;

    //1.�������������
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(-1);
    }

    //2.�����׽���
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) //����һ��С֪ʶ��: Ҳ���˰� AF_INET ���ɵȼ۵� PF_INET
    {
        log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
        exit(-1);
    }

    //3.���׽���
    //����һ�㲻��Ҫ����Ա�Լ� bind, ������Ϊ�ͻ����Ǳ��ͻ���ʹ�õ�, �������Ա�Լ� bind ��, 
    //��ô�ÿͻ��˵�һ���ǰ���ĳ���̶��� ip �� port ��һ�ڶ���������Ŀͻ���ͬʱ�����������, 
    //�ͻ���� port ��ʧ�ܵ����, �������¿ͻ�������ʧ�ܡ�
    //�� bind ������������ϵͳ����, ����ϵͳ������Щ port û�б�ռ�õ����������ˡ�

    //4.�洢��Ҫ���ʷ���˵� ip �� port
    struct sockaddr_in server;
    bzero(&server, sizeof(server)); //����λ����
    server.sin_family = AF_INET; //����Э�����/��
    server.sin_addr.s_addr = inet_addr(argv[1]); //���� ip�����ֽڣ�, �ڲ������������裺(1)ת��Ϊ���ֽ� (2)��ת��Ϊ��������
    server.sin_port = htons(atoi(argv[2])); //���� port�����ֽڣ�, ��������תΪ��������

    while (true)
    {
        //5.�����˷�����Ϣ message
        std::string message;
        std::cout << "clien >: ";
        std::getline(std::cin, message); //�û�������Ҫ���͵�����
        if (message == "exit")
            break;

        if (sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server)) >= 0) //д��ɹ�
        {
            //д��ɹ�, �������������е㷳��
            //Log.LogMessage(NORMAL, "client write done... %s %d", __FILE__, __LINE__);
        }
        else //д��ʧ��
        {
            log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //6.��ȡ����˷��ص���Ϣ
        char readBuff[readBuffSize] = { 0 }; //��һ�����������������ʱ, ����ϵͳ���� sendto() ִ�й��̳����Զ�Ϊ����˰�

        //ʵ���������Ѿ����˷���˵� ip �� port ����Ϣ��, ������ֻ��Ϊ��ռλ�͵��ù淶д��, �ڱ���Ŀ�п��Բ���ô������ʱ��ͻ��˿����������˵Ŀͻ��ˣ�
        struct sockaddr_in temp;
        bzero(&temp, sizeof(temp)); //����λ����
        socklen_t len = sizeof(temp);
        if (recvfrom(sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&temp, &len) >= 0)
        {
            std::cout << "server echo >: " << readBuff << std::endl;
        }
        else //��ȡʧ��
        {
            log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }
    }

    //7.�ر��׽���
    close(sock);
    log.LogMessage(NORMAL, "close udp client done... %s %d", __FILE__, __LINE__);
    std::cout << "bye~" << std::endl;

    return 0;
}