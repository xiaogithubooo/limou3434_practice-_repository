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
//    time_t timestamp = time(NULL); // ��ȡ��ǰʱ���
//    struct tm* local_time = localtime(&timestamp); // ��ʱ���ת��Ϊ����ʱ��
//
//    // �����������Ϣ
//    printf("Year: %d\n", local_time->tm_year + 1900); // tm_year�洢������1900������������
//    printf("Month: %d\n", local_time->tm_mon + 1); // tm_mon��ȡֵ��Χ��0-11����Ҫ��1����ʵ���·�
//    printf("Day: %d\n", local_time->tm_mday); // ���µĵڼ���
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