//log.hpp(Զ�̲�������)

/* ʹ�÷���
Log log = Log(bool debugShow = true,    //ѡ���Ƿ���ʾ DEBUG �ȼ�����־��Ϣ
    std::string writeMode = "SCREEN",   //ѡ����־�Ĵ�ӡ��ʽ
    std::string logFileName = "log"     //ѡ����־���ļ�����
);
log.WriteModeEnable();      //��;�����޸���־�Ĵ�ӡ��ʽ
log.LogMessage(DEBUG | NORMAL | WARNING | ERROR | FATAL, "%s %d", __FILE__, __LINE__));     //��ӡ��־
*/

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

//��־����
#define DEBUG 0 //����
#define NORMAL 1 //���������߽� INFO��
#define WARNING 2 //����
#define ERROR 3 //����
#define FATAL 4 //����

enum WriteMode
{
    SCREEN = 5,
    ONE_FILE,
    CLASS_FILE
};

const char* gLevelMap[] = {
    "DEBUG", //debug ģʽ
    "NORMAL", //���������߽� INFO��
    "WARNING", //����
    "ERROR", //����������
    "FATAL" //���ش���
};

const std::string logdir = "log_dir";

//��־������Ҫ�У���־�ȼ�������ʱ�䡢��־���ݡ����������������û�
class Log
{
private:
    void __WriteLogToOneFile(std::string logFileName, const std::string& message)
    {
        std::ofstream out(logFileName, std::ios::app);
        if (!out.is_open())
            return;
        out << message;
        out.close();
    }
    void __WriteLogToClassFile(const int& level, const std::string& message)
    {
        std::string logFileName = "./";
        logFileName += logdir;
        logFileName += "/";
        logFileName += _logFileName;
        logFileName += "_";
        logFileName += gLevelMap[level];

        __WriteLogToOneFile(logFileName, message);
    }
    void _WriteLog(const int& level, const std::string& message)
    {
        switch (_writeMode)
        {
        case SCREEN: //����Ļ���
            std::cout << message;
            break;
        case ONE_FILE: //�򵥸���־�ļ����
            __WriteLogToOneFile("./" + logdir + "/" + _logFileName, message);
            break;
        case CLASS_FILE: //������־�ļ����
            __WriteLogToClassFile(level, message);
            break;
        default:
            std::cout << "write mode error!!!" << std::endl;
            break;
        }
    }

public:
    //���캯����debugShow Ϊ�Ƿ���ʾ debug ��Ϣ��writeMode Ϊ��־��ӡģʽ��logFileName Ϊ��־�ļ���
    Log(bool debugShow = true, const WriteMode& writeMode = SCREEN, std::string logFileName = "log")
        : _debugShow(debugShow), _writeMode(writeMode), _logFileName(logFileName)
    {
        mkdir(logdir.c_str(), 0775); //����Ŀ¼
    }

    //������־��ӡ��ʽ
    void WriteModeEnable(const WriteMode& mode)
    {
        _writeMode = mode;
    }

    //ƴ����־��Ϣ�������
    void LogMessage(const int& level, const char* format, ...)
    {
        //1.������ debug ģʽ���� level == DEBUG �����κ�����
        if (_debugShow == false && level == DEBUG)
            return;

        //2.�ռ���־��׼������Ϣ
        char stdBuffer[1024];
        time_t timestamp = time(nullptr); //���ʱ���
        struct tm* local_time = localtime(&timestamp); //��ʱ���ת��Ϊ����ʱ��

        snprintf(stdBuffer, sizeof stdBuffer, "[%s][pid:%s][%d-%d-%d %d:%d:%d]",
            gLevelMap[level],
            std::to_string(getpid()).c_str(),
            local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
            local_time->tm_hour, local_time->tm_min, local_time->tm_sec
        );

        //3.�ռ���־�Զ��岿����Ϣ
        char logBuffer[1024];
        va_list args; //�����ɱ�����б�ʵ��ʱһ�� char* ����
        va_start(args, format); //��ʼ���ɱ�����б�
        vsnprintf(logBuffer, sizeof logBuffer, format, args); //int vsnprintf(char *str, size_t size, const char *format, va_list ap); ��һ���ɱ��������������ʽ������ַ���������������С����ƴ� v ��ͷ�Ŀɱ���������кܶ�
        va_end(args); //����ɱ�����б����� close() �� delete

        //4.ƴ��Ϊһ����������Ϣ
        std::string message;
        message += "--> ��׼��־:"; message += stdBuffer;
        message += "\t �û���־:"; message += logBuffer;
        message += "\n";

        //5.��ӡ��־��Ϣ
        _WriteLog(level, message);
    }

private:
    bool _debugShow;
    WriteMode _writeMode;
    std::string _logFileName;
};
