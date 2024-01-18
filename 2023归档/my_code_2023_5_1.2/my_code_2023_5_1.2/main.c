#define _CRT_SECURE_NO_WARNINGS 1
bool isValid(char* s)
{
    assert(s);
    Stack st2;//����һ��ջ
    StackInit(&st2);//��ʼ��ջ
    char cache = 0;
    while (*s)
    {
        switch (*s)
        {
        case '{':case '[':case '(':
            StackPush(&st2, *s);//ѹջ
            break;
        case '}':case ']':case ')':
        {
            if (!StackEmpty(&st2))//�ȼ���ջ�Ƿ�Ϊ�գ���Ϊ�շ���0����������������ᱨ����Ϊȡ������ջ/ɾ���˿�ջ�����һ�˳�������ֻ���������������ŵ����
            {
                cache = StackTop(&st2);//ȡ��ջԪ��
                StackPop(&st2);//ɾ��ջԪ��
                if ((*s == '}' && cache != '{') || (*s == ']' && cache != '[') || (*s == ')' && cache != '('))//���������
                {
                    StackDestroy(&st2);//����ջ
                    return false;
                }
                else//ƥ��ɹ�
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
    if (!StackEmpty(&st2))//��������ֻ����һ�������ŵ��������Ϊ�վͽ���
    {
        return false;
    }
    StackDestroy(&st2);//����ջ
    return true;
}
void test_3(void)
{
    char str[] = ")";
    if (isValid(str))
    {
        printf("ƥ��ɹ�\n");
    }
    else
    {
        printf("ƥ��ʧ��\n");
    }
}