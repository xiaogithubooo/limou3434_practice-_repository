//udp_server.cc
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

#include "udp_server.hpp"

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << "[ip] port\n" << std::endl;
}

int main(int argc, char* argv[]) //����������ָ�� ./udp_server ip port
{
    if (argc == 3)
    {
        std::string ip = argv[1]; //��ȡ ip ��ַ
        uint16_t port = atoi(argv[2]); //��ȡ�˿ں�
        std::unique_ptr<UdpServer> svr(new UdpServer(port, ip)); //ʹ������ָ���й�ָ�루�ں���ʼ����
        svr->Start();
    }
    else if (argc == 2)
    {
        uint16_t port = atoi(argv[1]); //��ȡ�˿ں�
        std::unique_ptr<UdpServer> svr(new UdpServer(port)); //ʹ������ָ���й�ָ�루�ں���ʼ����
        svr->Start();
    }
    else //������������
    {
        Usage(argv[0]);
        exit(10);
    }



    return 0;
}