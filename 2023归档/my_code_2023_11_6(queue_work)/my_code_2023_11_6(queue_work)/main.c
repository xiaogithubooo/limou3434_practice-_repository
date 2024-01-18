#include "function.h"

//1.界面函数
void menu()
{
    printf("-----------<通讯录>-------------\n");
    printf("--------<全屏体验更好>----------\n");
    printf("----  1、add     2、del     ----\n");
    printf("----  3、search  4、modify  ----\n");
    printf("----  5、show    6、sort    ----\n");
    printf("----  0、exit    7、word    ----\n");
    printf("--------------------------------\n");
    printf("---------<请选择选项>-----------\n");
}

//2.枚举结构体（增加代码可读性）
enum 
{
    EXIT,   //0
    ADD,    //1
    DEL,    //2
    SEARCH, //3
    MODIFY, //4
    SHOW,   //5
    SORT,   //6
    WORD    //7
};

//3.主体运行逻辑
int main()
{
    int input = 0;  //存储输入
    Contact con1;   //创建一份通讯录
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
            Save_Contact(&con1);
            Destroy_Contact(&con1);
            printf("退出通讯录\n");
            break;
        case WORD:
            printf("后续加上……\n");
            break;
        default:
            printf("**输入错误,请重新选择！**\n");
        }
    } while (input);//只要不输入0就可以循环
    return 0;
}