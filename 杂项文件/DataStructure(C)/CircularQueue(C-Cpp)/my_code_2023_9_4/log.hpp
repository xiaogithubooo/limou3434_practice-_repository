//log.hpp(�̳߳�)
#pragma once

#include <iostream>
#include <string>

#include <cstdio>
#include <cstdarg>
#include <ctime>

//��־����
#define DEBUG 0 //��ʽ
#define NORMAL 1 //���������߽� INFO��
#define WARNING 2 //����
#define ERROR 3 //����
#define FATAL 4 //����

const char* gLevelMap[] = {
    "DEBUG", //debug ģʽ
    "NORMAL", //���������߽� INFO��
    "WARNING", //����
    "ERROR", //����������
    "FATAL" //���ش���
};

//��־������Ҫ�У���־�ȼ�������ʱ�䡢��־���ݡ����������������û�
void LogMessage(int level, const char* format, ...)
{
    //ѡ���Ƿ���ʾ debug ģʽ
#ifndef DEBUG_SHOW //ע�⣬�ú���Ҫ�ڵ��� log.hpp ǰ������ܱ���֪
    if (level == DEBUG) return;
#endif

    //��־��׼���� 
    char stdBuffer[1024];
    time_t timestamp = time(nullptr); //���ʱ���
    struct tm* local_time = localtime(&timestamp); //��ʱ���ת��Ϊ����ʱ��

    snprintf(stdBuffer, sizeof stdBuffer, "[%s][%d-%d-%d]", gLevelMap[level], local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

    //��־�Զ��岿��
    char logBuffer[1024];
    va_list args; //�����ɱ�����б�ʵ��ʱһ�� char* ����
    va_start(args, format); //��ʼ���ɱ�����б�
    vsnprintf(logBuffer, sizeof logBuffer, format, args); //int vsnprintf(char *str, size_t size, const char *format, va_list ap); ��һ���ɱ��������������ʽ������ַ���������������С����ƴ� v ��ͷ�Ŀɱ���������кܶ�
    va_end(args); //����ɱ�����б����� close() �� delete

    //��׼+�Զ��岿��ֱ����ʾ����Ļ�ϣ�Ҳ����ѡ���ض�����־�ļ���)
    printf("| ��׼��־:%s | �Զ�����־:%s |\n", stdBuffer, logBuffer);

    //ѡ���Ƿ�洢��־�ļ�
#ifdef GET_LOG_FILE //ע�⣬�ú���Ҫ�ڵ��� log.hpp ǰ������ܱ���֪
    //���ļ���׷��ģʽ��
    FILE* file = fopen("log.txt", "a");
    if (file == nullptr) {
        perror("Error opening file");
        return;
    }

    //������׷�ӵ��ļ�ĩβ
    fprintf(file, "| ��׼��־:%s | �Զ�����־:%s |\n", stdBuffer, logBuffer);

    //�ر��ļ�
    fclose(file);
#endif
}