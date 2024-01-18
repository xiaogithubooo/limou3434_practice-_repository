//log.hpp
#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdarg>
#include <ctime>

//日志级别
#define DEBUG 0 //调式
#define NORMAL 1 //正常
#define WARNING 2 //警告
#define ERROR 3 //错误
#define FATAL 4 //致命

const char* gLevelMap[] = {
    "DEBUG", 
    "NORMAL", 
    "WARNING", 
    "ERROR", 
    "FATAL"
};

//日志功能主要有：日志等级+发送时间+日志内容/自定义日志内容+Other（代码行数+运行用户）
void LogMessage(int level, const char *format, ...)
{
    //日志标准部分 
    char stdBuffer[1024];
    time_t timestamp = time(nullptr); 
    snprintf(stdBuffer, sizeof stdBuffer, "[%s][%d]", gLevelMap[level], timestamp);
    // va_list ap;
    // va_start(ap, format);
    // int x = va_arg(ap, int);
    // va_end(ap);

    //日志自定义部分
    char logBuffer[1024];

    va_list args;
    va_start(args, format);
    vsnprintf(logBuffer, sizeof logBuffer, format, args);
    va_end(args);

    printf("%s %s\n", stdBuffer, logBuffer);
}