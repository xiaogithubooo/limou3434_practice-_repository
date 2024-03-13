//log.hpp(远程操作程序)
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
    "DEBUG", //debug 模式
    "NORMAL", //正常
    "WARNING", //警告
    "ERROR", //错误
    "FATAL" //严重错误
};

//日志功能主要有：日志等级+发送时间+日志内容/自定义日志内容+Other（代码行数+运行用户）
void LogMessage(int level, const char *format, ...)
{
#ifndef DEBUG_SHOW
    if (level == DEBUG) return;
#endif
    //日志标准部分 
    char stdBuffer[1024];
    time_t timestamp = time(nullptr); 
    snprintf(stdBuffer, sizeof stdBuffer, "[%s][%d]", gLevelMap[level], timestamp);

    //日志自定义部分
    char logBuffer[1024];
    va_list args; //声明可变参数列表
    va_start(args, format); //初始化可变参数列表
    vsnprintf(logBuffer, sizeof logBuffer, format, args); //int vsnprintf(char *str, size_t size, const char *format, va_list ap); 是一个可变参数函数，将格式化的字符串输出到缓冲区中
    va_end(args); //清理可变参数列表

    //标准+自定义部分直接显示到屏幕上（也可以选择重定向到日志文件里)
    printf("| 标准日志:%s | 自定义日志:%s |\n", stdBuffer, logBuffer);
}