#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include <iostream>
#include <string>

#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

const int readBuffSize = 1024;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " serverIp serverPort\n" << std::endl;
}

int main(int argc, char* argv[]) // ./udp_client 127.0.0.1 8080
{
    //1.�������������
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(50);
    }

    //2.��ʼ�� WinSock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup error" << std::endl;
        exit(60);
    }

    //3.�����׽���
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "socket error" << std::endl;
        WSACleanup();
        exit(70);
    }

    //4.�����˷�������
    std::string message;

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    char readBuff[readBuffSize] = { 0 };
    while (true)
    {
        std::cout << "������������ź�" << std::endl;
        std::getline(std::cin, message);
        if (message == "exit") // �����Ƚ��ַ����ķ�ʽ
            break;

        sendto(sock, message.c_str(), message.size(), 0,
            (struct sockaddr*)&server, sizeof(server));

        //5.��ȡ����˷��ص�����
        sockaddr_in temp; //ռλ��
        int len = sizeof(temp);
        int s = recvfrom(sock, readBuff, sizeof(readBuff), 0,
            (struct sockaddr*)&temp, &len);
        if (s > 0)
        {
            std::cout << "server echo# " << readBuff << std::endl;
        }
        else
        {
            std::cerr << "read error" << std::endl;
            closesocket(sock);
            WSACleanup();
            exit(80);
        }
    }

    closesocket(sock);
    WSACleanup();
    std::cout << "bye~" << std::endl;

    return 0;
}
