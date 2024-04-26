//task.hpp(�̳߳ذ汾�ķ����)

/* ʹ�÷���
Task t = Task(������1, ������2, ������);
t.Run(); �� �º��� t(); ������ִ������, ���ҷ��ؽ��
t.Show(); �鿴����ľ�������
*/

#pragma once
#include <iostream>
#include <string>
#include <functional>

//������
class Task
{
public:
    using task_func_t = std::function<void(int sock, const std::string ip, uint16_t port)>;


public:
    //����ն���
    Task() {}

    //�����׽��������Ϣ��һ������ص�
    Task(int sock, const std::string ip, uint16_t port, task_func_t func)
        : _sock(sock)
        , _ip(ip)
        , _port(port)
        , _func(func) //�ڶ��̵߳ķ��������, �����������Ӧ�����ٴ��һ������˵��׽���
    {}

    //�º���, �ö�����Ե�������ص�
    void operator()()
    {
        _func(_sock, _ip, _port);
    }


private:
    int _sock;
    std::string _ip;
    uint16_t _port;
    task_func_t _func;
};