//tcp_server.hpp(���̷߳����)

/* ʹ�÷���
std::unique_ptr<TcpServer> svr(new TcpServer(port, ip));
svr->Start();
*/

#pragma once
#include <string>
#include <cerrno>
#include <cstring>
#include <cassert>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "log.hpp"
#include "thread.hpp"

const int buffSize = 1024;
const int g_backlog = 20; //�����ֵһ�㲻��̫��, Ҳ����̫С, ���������Ժ��ἰ TCP ���ĵ�ʱ��������ϸ����

//�߳�������
struct ThreadData
{
    int _sock;
    std::string _ip;
    uint16_t _port;
};

static void Service(const int& serviceSock, const std::string& client_ip, const uint16_t& client_port)
{
    Log log;

    while (true)
    {
        //ֱ�������ļ� IO �Ľӿ� read() �� write()

        //�ӷ���˶�ȡ����
        char readBuffer[1024] = { 0 };
        ssize_t s = read(serviceSock, readBuffer, sizeof(readBuffer) - 1);
        if (s > 0)
        {
            std::cout << "[" << client_ip << ":" << client_port << "] echo " << readBuffer << std::endl;
        }
        else if (s == 0) //����Զ˹ر���
        {
            log.LogMessage(NORMAL, "write close, me too! %s %d", __FILE__, __LINE__);
            break;
        }
        else //�����ȡ�����쳣
        {
            log.LogMessage(FATAL, "read() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //д�����ݵ������
        write(serviceSock, readBuffer, strlen(readBuffer)); //�������ʲô���ݾ�ֱ�Ӵ��ͻ�ȥ
    }
}

class TcpServer
{
private:
    static void* ThreadRoutine(void* args) //static ȥ�� this ����
    {
        pthread_detach(pthread_self()); //�̷߳���, �����߳��Լ��ͷ��Լ�

        ThreadData* td = (ThreadData*)args;

        int serviceSock = td->_sock;
        std::string client_ip = td->_ip;
        int client_port = td->_port;

        Service(serviceSock, client_ip, client_port); //��д����

        delete td; //��һ��һ��Ҫ��ס
    }

public:
    //��ʼ������
    TcpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _ListenSock(-1)
    {
        //1.�����׽���
        if ((_ListenSock = socket(AF_INET, SOCK_STREAM, 0)) < 0) //ע�⻻����ʽ����, ���������ݱ�����
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }
        _log.LogMessage(NORMAL, "sock: %d, %s %d", _ListenSock, __FILE__, __LINE__); //�����׽����ǲ��������һ���ļ�������, ������Ӧ���� 3

        //2.���׽���
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //����λ����
        local.sin_family = AF_INET; //����Э�����/��
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //���� ip(���ֽ�), �ڲ������������裺(1)ת��Ϊ���ֽ� (2)��ת��Ϊ��������
        local.sin_port = htons(_port); //���� port(���ֽ�), ��������תΪ��������
        if (bind(_ListenSock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //3.�����׽���Ϊ����״̬
        /* ��Ϊ TCP ���������ӵ�, �����ȷͨ��ʱ��Ҫ��������, �����ע��һ������˱��봦��һ���ȴ����ӵ�״̬ */
        if (listen(_ListenSock, g_backlog) < 0) //���� _ListenSock Ϊ����״̬
        {
            _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //4.��ʾ��ʼ���ɹ�
        _log.LogMessage(NORMAL, "init tcp server done... %s %d", __FILE__, __LINE__);
    }

    //���з�����
    void Start()
    {
        //signal(SIGCHLD, SIG_IGN); //�������ɳ���Ա�������ú���, ����ӽ����˳�ʱ���Զ��ͷ��Լ��Ľ�ʬ״̬

        while (true)
        {
            //1.��ȡ�Ϳͻ��˵����ӣ����û���κ�һ���ͻ������ӷ����, ����˾ͻ���������״̬��
            struct sockaddr_in src;
            socklen_t len = sizeof(src);
            int serviceSock = accept(_ListenSock, (struct sockaddr*)&src, &len); //��ȡ IO �õ��׽���(����׽��ֲ����� IO ������׽���, ��֮ǰ����� _ListenSock Ӧ�ý��������׽���)
            /* _ListenSock vs serviceSock ? ע������� _ListenSock ��ʵ����֮ǰ�����е� _sork, �����һ���һ�����Ӽ������� */
            /* �������׽��ֵ���������ڣ�_ListenSock ���ṩ���͵�����Ա, serviceSock ���ṩ����ķ���Ա */
            /* _ListenSock �����ǻ�ȡ�µ�����, serviceSock �������ṩ IO ����, ���� UDP ��̺ܲ�һ�� */

            if (serviceSock < 0) //������
            {
                _log.LogMessage(WARNING, "accept() error... , %s %d", __FILE__, __LINE__);
                continue; //��ʹ��ȡ�����µ�����Ҳ��Ӱ��, ����ѭ���������Ӽ���
            }

            std::string client_ip = inet_ntoa(src.sin_addr);
            uint16_t client_port = ntohs(src.sin_port);
            _log.LogMessage(NORMAL, "link success, the \"service sock\" is [%d], the \"client sock\" is [%s:%d], %s %d", serviceSock, client_ip.c_str(), client_port, __FILE__, __LINE__); //��ʾ���ӳɹ�

            //2.��ʼ����ͨ�ŷ���
            //version 1 -- ������ѭ���汾
            //Service(serviceSock, client_ip, client_port);

            //version 2 -- �����ѭ���汾
            //pid_t id = fork(); //�����ӽ���
            //assert(id != -1);
            //if (id == 0) //�ӽ���, Ҳ�ܿ����ļ�������, ���Ҳ�����ṩ������, �����ӹ�������������
            //{
            //    close(_ListenSock); //�����ӽ�������֪�������׽���, �رռ���, �����ļ���������ԴԽ��Խ��
            //    Service(serviceSock, client_ip, client_port); //ִ�з�������
            //    close(serviceSock); //��������ִ�н�������ùر��·����׽���(��Ȼ�ý����Զ��ͷź�Ҳ���Զ��ͷŸ��׽�����Դ����, ���������Ͻ�һ��)
            //    exit(-1);
            //}
            //waitpid(); //�����Ҳ����÷������ȴ�����, Ҳ�������ӽ����˳�ʱ�źŵĴ������, ����ʹ���źź��Եķ�ʽ, ��Ӧ������� Start() �����Ŀ�ͷ��

            //version 3 -- �����ѭ���汾��������йܰ汾��
            //pid_t id = fork(); //�����ӽ���
            //if (id == 0) //(2)�ӽ��̲���
            //{
            //    close(_ListenSock); //��ǰ�رռ����׽���, ��������̾Ͳ����ٴιر���
            //    if (fork() > 0) //�ӽ��̴��������̺߳�, �Լ������˳�
            //        exit(-1);
            //    //(3)����̲���
            //    Service(serviceSock, client_ip, client_port); //����̱��ӽ�������, ��Ϊ�¶����̱�����ϵͳ����, ����ɲ���ϵͳ�����ͷ�(�൱���ɲ���ϵͳ�Զ��ͷ�)
            //    close(serviceSock); //ִ������������, �رշ����׽���
            //    exit(-1); //ע�����������ִ�����Լ��������һ��Ҫ�˳�, ��Ȼ��������벻���Ĵ���(�����ڿͻ���ʹ�� "exit" �˳�ʱ�ᵼ�¸�����������ѭ��, ����������о�һ��)
            //}
            //waitpid(id, nullptr, 0); //�����������ȴ������ӽ���, �����ӽ��������˳�, ��˸����̿������̽����ӽ����ٽ����ͷŲ��ᵼ�¸����̽�������, ������̴�ʱ����ִ�кͷ���˽���������
            ////(1)�����̲���
            
            //version 4 -- ���̰߳汾
            //pthread_t tid;
            //ThreadData* td = new ThreadData(); //���������ָ��, ��Ϊ�п����ڶ��̵߳ĳ����� td ����������, ���������ü���... �������۾��Ǳ���ע�����̷߳������ͷ�ָ��
            //td->_sock = serviceSock;
            //td->_ip = client_ip;
            //td->_port = client_port;
            //pthread_create(&tid, nullptr, ThreadRoutine, td);
            
            //version 5 -- ���̰߳汾(�Լ���װ���̶߳���)
            ThreadData* td = new ThreadData(); //���������ָ��, ��Ϊ�п����ڶ��̵߳ĳ����� td ����������, ���������ü���... �������۾��Ǳ���ע�����̷߳������ͷ�ָ��
            td->_sock = serviceSock;
            td->_ip = client_ip;
            td->_port = client_port;
            Thread<ThreadData*> t("aThread", ThreadRoutine, td);
            t.Start();

            //3.�رշ����׽���(���̰߳汾���ܹر�, ����ᵼ�·���˱��쳣�ر�, ��Ҳ�ܺ����, ���ﲻ�Ƕ����, ���̹߳رշ����׽��ֻᵼ�¹�������̶߳�д�׽���ʱ���ִ���)
            //close(serviceSock);
        }
    }

    //���ٷ�����
    ~TcpServer()
    {
        if (_ListenSock < 0)
            close(_ListenSock);
    }


private:
    std::string _ip;
    uint16_t _port;
    int _ListenSock; //int _sock; //���Ǹ�Ը�������׽���Ϊ�����׽���, ������Ǹ�һ������
    Log _log;
};