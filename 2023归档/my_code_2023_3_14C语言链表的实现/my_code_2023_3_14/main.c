#define _CRT_SECURE_NO_WARNINGS 1

//1��������Ľṹ��
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;//����������
typedef struct SListNode //��������
{
    SListDataType data;//�洢����
    struct SListNode* next;//���ﲻ�ǽṹ���׽ṹ�壬��������һ��ָ�룬ָ����һ���ṹ�壨�;͵�����һ����ַ�������������Ƕ�׵������
}SListNode;

//2������ڵ�ӿں���
void SList_Push_Back(SListNode** pphead, SListDataType x)//(����һ���ڵ�ĵ�ַ�ĵ�ַ,����һ������)
{
    //ע�ⲻҪд���β��ˣ���д��SListNode*�ˣ���ᵼ�º���newnode�����βζ�û��ʵ�Σ���back��β������˼

    //1�������γ�һ�������ڵ�Ĵ洢�ռ䣬���Ҹ����Աֵ���г�ʼ��
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    assert(newnode);
    newnode->data = x;//�洢һ������
    newnode->next = NULL;//��������Ϊβ�ڵ㣬��˲����ܵ�֪��һ���ڵ�ĵ�ַ

    //2�������ǽ����浥���Ľڵ�����Ϊ�������β�ڵ�
    if (*pphead == NULL)//˵����ʱ����һ���ڵ㶼û��
    {
        *pphead = newnode;//�Ǿ��ȴ���һ�����
    }
    else//˵����ʱ����������һ���ڵ�
    {
        //���ҵ���ǰ����β�ڵ�Ŀ�ָ�룬ֱ���ҵ�Ϊֹ
        SListNode* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        //�ڽ������β�ڵ��ָ�룬����Ϊָ����β�ڵ��ָ��
        tail->next = newnode;
    }
}

//3������ͷ��ӿں���
void SList_Push_Front(SListNode** pphead, SListDataType x)
{
    //1�������γ�һ�������ڵ�Ĵ洢�ռ䣬���Ҹ����Աֵ���г�ʼ��
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    assert(newnode);
    newnode->data = x;//�洢һ������
    newnode->next = NULL;
    //2������ͷ��
    newnode->next = *pphead;
    *pphead = newnode;
}

//4������βɾ�ӿں���
void SList_Pop_Back(SListNode** pphead)
{
    if (*pphead == NULL)//������ڵ�
    {
        return;
    }
    else if ((*pphead)->next == NULL)//��һ���ڵ㣬ע�������������
    {
        free(*pphead);
        *pphead = NULL;
    }
    else//�����������ڵ�
    {
        SListNode* prev = NULL;
        SListNode* tail = *pphead;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}

//5������ͷɾ�ӿں���
void SList_Pop_Front(SListNode** pphead)
{
    assert(*pphead);//ע�����������Լ��ӵģ�����������ָ�������
    SListNode* next = (*pphead)->next;//�����ȼ������ͷ�ڵ�洢��ָ����һ������ָ������
    free(*pphead);//����ֱ��ֻ�������䣬��ֱ���Ҳ��������������ӵ����޷����ն�̬�ڴ棬���ڵĻ������ڴ�й©
    *pphead = next;//��ԭ���ĵڶ��ڵ���ͷ�ڵ�
}

//7��������ҽӿں���
SListNode* SList_Find(SListNode* phead, SListDataType x)
{
    SListNode* cur = phead;
    while (cur)//�ȼ���while(cur != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//8�������������ӿں�������ͬ�̿��鲻̫һ������������posǰ�����x��
//�����ú���void SList_Find�����ٽ����������
void SList_Insert(SListNode** pphead, SListNode* pos, SListDataType x)
{
    if(pos == *pphead)//0������ǲ���ͷ�ڵ㣬���൱��ͷ��
    {
        SList_Push_Front(pphead, x);
    }
    else
    {
        //1���ȵõ�һ��ռ�洢�½ڵ�
        SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
        assert(newnode);
        newnode->data = x;//�洢һ������
        newnode->next = NULL;//�����ܵ�֪��һ���ڵ�ĵ�ַ

        //2���ҵ�ָ����ַpos��ǰһ����ַ�����½ڵ����
        SListNode* prev = *pphead;
        while (prev->next != pos)//�ӵ�һ������ʼ���磬ֱ����һ���ڵ��ڲ���Ա�����һ����ַΪNULL����ʱͣ����pos�ڵ��ǰһ���ڵ�
        {
            prev = prev->next;
        }
        prev->next = newnode;
        newnode->next = pos;
    }
}

//9����������ɾ���ӿں�������ͬ�̿��鲻̫һ����
//�����ú���void SList_Find�����ٽ�������ɾ��
void SList_Erase(SListNode** pphead, SListNode* pos)
{
    assert(*pphead);    
    if (pos == *pphead)//1������ǲ���ͷ�ڵ㣬���൱��ͷɾ
    {
        SList_Pop_Front(pphead);
    }
    else//2����ͷ�ڵ㴦
    {
        SListNode* prev = *pphead;
        while (prev->next != pos)//�ӵ�һ������ʼ���磬ֱ����һ���ڵ��ڲ���Ա�����һ����ַΪNULL����ʱͣ����pos�ڵ��ǰһ���ڵ�
        {
            prev = prev->next;
        }
        prev->next = pos->next;//���������Ͽ��Ľڵ�
        free(pos);//�ͷ�ɾ���ڵ���ڴ�
    }
}

//10�������ӡ�ӿں���
void SList_Print(SListNode* phead)
{
    SListNode* cur = phead;//���ڵ�ĵ�ַ�洢����
    while (cur != NULL)//�״ν����ڵ��ַ��Ϊ�գ�˵�������ݴ��ڽڵ�������
    {
        printf("%d -> ", cur->data);
        cur = cur->next;//��cur�ӡ�ָ���׽��ĵ�ַ������ɡ�ָ����һ����ֵַ��
    }
    printf("NULL\n");
}
void Test_SList()
{
    SListNode* plist = NULL;//plistָ��һ����㣬�������ڸ�ֵNULL������ֻ�ǳ�ʼ����һ������ָ�����ָ��

    //1.�����Ƿ�β�����½ڵ�
    SList_Push_Back(&plist, 1);
    SList_Push_Back(&plist, 2);
    SList_Push_Back(&plist, 3);
    SList_Push_Back(&plist, 4);
    SList_Print(plist);

    //2.�����Ƿ�ͷ�����½ڵ�
    SList_Push_Front(&plist, -3);
    SList_Push_Front(&plist, -2);
    SList_Push_Front(&plist, -1);
    SList_Push_Front(&plist, -0);
    SList_Print(plist);

    //3.�����Ƿ�βɾ��
    SList_Pop_Back(&plist);
    SList_Pop_Back(&plist);
    SList_Print(plist);

    //4.�����Ƿ�ͷɾ��
    SList_Pop_Front(&plist);
    SList_Pop_Front(&plist);
    SList_Print(plist);

    //5.�����ܷ�����ĳ���ڵ�����
    printf("%p\n", SList_Find(plist, 1));//����1��λ��

    //6.1.�����ܷ�����ĳ���ڵ㣬Ȼ����ǰ������½ڵ�
    SListNode* pos = SList_Find(plist, 1);
    if (pos)
    {
        SList_Insert(&plist, pos, 30);
    }
    SList_Print(plist);
    //6.2.�����ܷ���ͷ�ڵ�ǰ������½ڵ�
    pos = SList_Find(plist, -2);
    if (pos)
    {
        SList_Insert(&plist, pos, 100);
    }
    SList_Print(plist);

    //7.1.�����ܷ�����ĳ���ڵ㣬Ȼ��ɾ��
    pos = SList_Find(plist, -3);
    {
        SList_Erase(&plist, pos);
    }
    SList_Print(plist);
    //7.2.�����ܷ�ɾ��ͷ�ڵ�
    pos = SList_Find(plist, 100);
    {
        SList_Erase(&plist, pos);
    }
    SList_Print(plist);
}
int main()
{
    Test_SList();
    return 0;
}