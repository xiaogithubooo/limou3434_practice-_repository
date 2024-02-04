//udp_client.cc
#include <iostream>
#include <string>

#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

const int readBuffSize = 1024;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << "serverIp serverPort\n" << std::endl;
}

int main(int argc, char* argv[]) //./udp_client 127.0.0.1 8080
{
    //1.�������������
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(50);
    }

    //2.�����׽���
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        std::cerr << "socket error" << std::endl;
        exit(60);
    }

    //3.���׽���
    //����һ�㲻��Ҫ����Ա�Լ� bind��������Ϊ�ͻ����Ǳ��ͻ���ʹ�õģ��������Ա�Լ� bind �ˣ���ô�ÿͻ��˵�һ���ǰ���ĳ���̶��� ip �� port
    //��һ�ڶ���������Ŀͻ���ͬʱ����������£��ͻ���� port ��ʧ�ܵ�������������¿ͻ�������ʧ�ܣ�
    //�� bind ������������ϵͳ����������ϵͳ������Щ port û�б�ռ�õ�����������

    //4.�����˷�������
    std::string message;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    char readBuff[readBuffSize] = { 0 };
    while (true)
    {
        std::cout << "������������ź�" << std::endl;
        std::getline(std::cin, message);
        if (message.c_str() == "exit")
            break;

        sendto(sock, message.c_str(), message.size(), 0,
            (struct sockaddr*)&server, sizeof(server));
        //��һ�����������������ʱ������ϵͳ���� sendto() ִ�й��̳����Զ�Ϊ����˰�

        //5.��ȡ����˷��ص�����
        struct sockaddr_in temp; //ռλ��
        socklen_t len = sizeof(temp);
        ssize_t s = recvfrom(sock, readBuff, sizeof(readBuff), 0,
            (struct sockaddr*)&temp, &len);
        if (s > 0)
        {
            std::cout << "server echo# " << readBuff << std::endl;
        }
        else
        {
            std::cerr << "read error" << std::endl;
            exit(70);
        }
    }

    close(sock);
    std::cout << "bye~" << std::endl;

    return 0;
}