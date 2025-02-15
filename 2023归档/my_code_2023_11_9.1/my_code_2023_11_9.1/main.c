#include "function.h"
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
    Contact con1;//创建一份通讯录
    Init_Contact(&con1);//该函数定义被修改了
    do
    {
        menu();
        int scanf_number = scanf("%d", &input);
        switch (input)
        {
        case ADD:
            Add_Contact(&con1);//该函数定义被修改了
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
            Save_Contact(&con1);//这个函数又是新增加的
            Destroy_Contact(&con1);//该函数是新增加的
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