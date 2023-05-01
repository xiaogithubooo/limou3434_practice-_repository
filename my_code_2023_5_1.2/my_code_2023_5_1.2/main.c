#define _CRT_SECURE_NO_WARNINGS 1
bool isValid(char* s)
{
    assert(s);
    Stack st2;//创建一个栈
    StackInit(&st2);//初始化栈
    char cache = 0;
    while (*s)
    {
        switch (*s)
        {
        case '{':case '[':case '(':
            StackPush(&st2, *s);//压栈
            break;
        case '}':case ']':case ')':
        {
            if (!StackEmpty(&st2))//先检验栈是否为空（不为空返回0），否则后续操作会报错，因为取出来空栈/删除了空栈，并且还顺带解决了只传过来右类型括号的情况
            {
                cache = StackTop(&st2);//取出栈元素
                StackPop(&st2);//删除栈元素
                if ((*s == '}' && cache != '{') || (*s == ']' && cache != '[') || (*s == ')' && cache != '('))//不符合情况
                {
                    StackDestroy(&st2);//销毁栈
                    return false;
                }
                else//匹配成功
                {
                    ;
                }
            }
            else
            {
                return false;
            }
            break;
        }
        default:
            break;
        }
        ++s;
    }
    if (!StackEmpty(&st2))//避免类似只存了一个左括号的情况，不为空就进入
    {
        return false;
    }
    StackDestroy(&st2);//销毁栈
    return true;
}
void test_3(void)
{
    char str[] = ")";
    if (isValid(str))
    {
        printf("匹配成功\n");
    }
    else
    {
        printf("匹配失败\n");
    }
}