#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{

    // ���ļ��Խ���д��
    FILE* file = fopen("test.txt", "wb");

    // ʹ�� fwrite д������
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