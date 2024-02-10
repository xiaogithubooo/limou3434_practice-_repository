#pragma warning(disable:4996)
#include <WinSock2.h>
#include <iostream>
#include <string>

#pragma comment(lib,"ws2_32.lib") //��һ������� Windows ���׽��ֱ�̵Ĺ̶��÷���Windows ���е�

uint16_t serverport = 8080;
std::string serverip = "111.230.60.61";

int main()
{
	WSADATA WSAData;
	WORD sockVersion = MAKEWORD(2, 2); //���ÿ�汾��Windows ���е�
	if (WSAStartup(sockVersion, &WSAData) != 0) //���ݰ汾���ض�Ӧ�Ŀ⣬Windows ���е�
		return 0;

	//��ʼ�׽��ֱ��
	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == clientSocket)
	{
		std::cout << "socket error!";
		return 0;
	}

	sockaddr_in dstAddr;
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_port = htons(serverport);
	dstAddr.sin_addr.S_un.S_addr = inet_addr(serverip.c_str());

	while (true)
	{
		char buffer[1024] = { 0 };

		std::string message;
		std::cout << "������# ";
		std::getline(std::cin, message);
		sendto(clientSocket, message.c_str(), (int)message.size() - 1, 0, (sockaddr*)&dstAddr, (int)sizeof(dstAddr));

		struct sockaddr_in temp;
		int len = sizeof(temp);
		if (recvfrom(clientSocket, buffer, sizeof buffer, 0, (sockaddr*)&temp, &len) > 0)
		{
			std::cout << "server echo# " << buffer << std::endl;
		}
	}
	
	closesocket(clientSocket); //�ر��ļ���������windows ���е�
	WSACleanup(); //�������windows ���е�

	return 0;
}
