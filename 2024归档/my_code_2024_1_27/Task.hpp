#pragma once
//内含任务的相关信息
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>

#include <unistd.h>
using namespace std;

//包装类
using task_t = function<void()>; //typedef function<void()> task_t

//查询数据
void ReadSQL()
{
    sleep(3);
    cout << "process[" << getgid() << "] 执行了访问数据库的任务" << endl;
}
//解析地址
void ExeculeUrl()
{
    sleep(3);
    cout << "process[" << getgid() << "] 执行了解析URL地址的任务" << endl;
}
//加密任务
void Cal()
{
    sleep(3);
    cout << "process[" << getgid() << "] 执行了加密的任务" << endl;
}
//数学计算
void MathCalculate()
{
    sleep(3);
    cout << "process[" << getgid() << "] 执行了数学计算的任务" << endl;
}

//任务类
class Tasks
{
public:
    //转载任务，并且构建哈希映射
    Tasks()
    {
        _tasks.push_back(ReadSQL);
        _tasks.push_back(ExeculeUrl);
        _tasks.push_back(Cal);
        _tasks.push_back(MathCalculate);

        _list[0] = "ReadSQL";
        _list[1] = "ExeculeUrl";
        _list[2] = "Cal";
        _list[3] = "MathCalculate";
    }

    //检查任务码是否合法
    bool CheckSafe(const int& code)
    {
        if (code >= 0 && code < _tasks.size())
            return true;
        return false;
    }

    //执行任务
    void RunTask(const int& code)
    {
        _tasks[code]();
    }

    //任务展示
    string TaskShow(const int& code)
    {
        return _list[code];
    }

    //显示任务列表
    void ShowTaskList()
    {
        for (int i = 0; i < _list.size(); i++)
        {
            cout << "code:" << i << ", name:" << TaskShow(i) << endl;
        }
    }

private:
    vector<task_t> _tasks; //任务集合
    unordered_map<int, string> _list; //任务码和任务的映射
};

Tasks tasks; //全局对象，在 main() 启动前自动装载任务