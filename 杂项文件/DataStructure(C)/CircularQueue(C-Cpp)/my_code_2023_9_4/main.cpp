#define _CRT_SECURE_NO_WARNINGS 1
#define DEBUG_SHOW
//#define GET_LOG_FILE
#include "log.hpp"
int main()
{
	LogMessage(DEBUG, "%s %d", __FILE__, __LINE__);
	LogMessage(WARNING, "%s %d", __FILE__, __LINE__);
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <time.h>
//
//int main() {
//    time_t timestamp = time(NULL); // 获取当前时间戳
//    struct tm* local_time = localtime(&timestamp); // 将时间戳转换为本地时间
//
//    // 输出年月日信息
//    printf("Year: %d\n", local_time->tm_year + 1900); // tm_year存储的是自1900年以来的年数
//    printf("Month: %d\n", local_time->tm_mon + 1); // tm_mon的取值范围是0-11，需要加1才是实际月份
//    printf("Day: %d\n", local_time->tm_mday); // 当月的第几天
//
//    return 0;
//}
//
////#include "circular_queue.hpp"
////int main()
////{
////	test();
////	return 0;
////}