//log.hpp(线程池)
#pragma once

#include <iostream>
#include <string>

#include <cstdio>
#include <cstdarg>
#include <ctime>

//日志级别
#define DEBUG 0 //调式
#define NORMAL 1 //正常（或者叫 INFO）
#define WARNING 2 //警告
#define ERROR 3 //错误
#define FATAL 4 //致命

const char* gLevelMap[] = {
    "DEBUG", //debug 模式
    "NORMAL", //正常（或者叫 INFO）
    "WARNING", //警告
    "ERROR", //非致命错误
    "FATAL" //严重错误
};

//日志功能主要有：日志等级、发送时间、日志内容、代码行数、运行用户
void LogMessage(int level, const char* format, ...)
{
    //选择是否显示 debug 模式
#ifndef DEBUG_SHOW //注意，该宏需要在导入 log.hpp 前定义才能被感知
    if (level == DEBUG) return;
#endif

    //日志标准部分 
    char stdBuffer[1024];
    time_t timestamp = time(nullptr); //获得时间戳
    struct tm* local_time = localtime(&timestamp); //将时间戳转换为本地时间

    snprintf(stdBuffer, sizeof stdBuffer, "[%s][%d-%d-%d]", gLevelMap[level], local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

    //日志自定义部分
    char logBuffer[1024];
    va_list args; //声明可变参数列表，实际时一个 char* 类型
    va_start(args, format); //初始化可变参数列表
    vsnprintf(logBuffer, sizeof logBuffer, format, args); //int vsnprintf(char *str, size_t size, const char *format, va_list ap); 是一个可变参数函数，将格式化后的字符串输出到缓冲区中。类似带 v 开头的可变参数函数有很多
    va_end(args); //清理可变参数列表，类似 close() 和 delete

    //标准+自定义部分直接显示到屏幕上（也可以选择重定向到日志文件里)
    printf("| 标准日志:%s | 自定义日志:%s |\n", stdBuffer, logBuffer);

    //选择是否存储日志文件
#ifdef GET_LOG_FILE //注意，该宏需要在导入 log.hpp 前定义才能被感知
    //打开文件（追加模式）
    FILE* file = fopen("log.txt", "a");
    if (file == nullptr) {
        perror("Error opening file");
        return;
    }

    //将内容追加到文件末尾
    fprintf(file, "| 标准日志:%s | 自定义日志:%s |\n", stdBuffer, logBuffer);

    //关闭文件
    fclose(file);
#endif
}