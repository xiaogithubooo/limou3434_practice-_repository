#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
    printf("-----------<ͨѶ¼>-------------\n");
    printf("--------<ȫ���������>----------\n");
    printf("----  1��add     2��del     ----\n");
    printf("----  3��search  4��modify  ----\n");
    printf("----  5��show    6��sort    ----\n");
    printf("----  0��exit    7��word    ----\n");
    printf("--------------------------------\n");
    printf("---------<��ѡ��ѡ��>-----------\n");
}

enum {
    EXIT,//0
    ADD,//1
    DEL,//2
    SEARCH,//3
    MODIFY,//4
    SHOW,//5
    SORT,//6
    WORD//7
};

int main()
{
    int input = 0;
    Contact con1;//����һ��ͨѶ¼
    Init_Contact(&con1);
    do
    {
        menu();
        int scanf_number = scanf("%d", &input);
        switch (input)
        {
        case ADD:
            Add_Contact(&con1);
            break;
        case DEL:
            Dle_Contact(&con1);
            break;
        case SEARCH:
            Search_Contact(&con1);
            break;
        case MODIFY:
            Modify_Contact(&con1);
            break;
        case SHOW:
            Show_Contact(&con1);
            break;
        case SORT:
            Sort_Contact(&con1);
            break;
        case EXIT:
            printf("�˳�ͨѶ¼\n");
            break;
        case WORD:
            printf("�������ϡ���\n");
            break;
        default:
            printf("**�������,������ѡ��**\n");
        }
    } while (input);//ֻҪ������0�Ϳ���ѭ��
    return 0;
}
