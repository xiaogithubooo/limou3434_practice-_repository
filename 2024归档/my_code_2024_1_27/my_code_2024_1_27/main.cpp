#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{

    // 打开文件以进行写入
    FILE* file = fopen("test.txt", "wb");

    // 使用 fwrite 写入数据
    char data[] = "Hello, World!";
    size_t size = sizeof(char);
    size_t count = sizeof(data) / size;
    int c = 20;

    while (c--)
    {
        size_t written = fwrite(data, size, count, file);
        cout << "hello" << endl;
        Sleep(1000);
    }

    fclose(file);
	return 0;
}