#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int scanfNumber = 0;

int Check_Capacity(Contact* pcon);//由于下面这个函数要用到所以必须提前再声明一次
void Load_Contact(Contact* pcon)//注意这里又新增一个函数
{
    //打开文件
    FILE* pf = fopen("limou_contact.data", "rb");
    if (pf == NULL)
    {
        perror("Load_Contact::");
        return 1;
    }
    //加载数据（读文件）
    PeoInfo tmp = { 0 };//暂时存储之前的数据
    while (fread(&tmp, sizeof(PeoInfo), 1, pf))
    {
        Check_Capacity(pcon);
        pcon->data[pcon->sz] = tmp;//C是允许结构体变量直接赋值操作的
        pcon->sz++;
    }
    //关闭文件
    fclose(pf);
    pf = NULL;
}
void Init_Contact(Contact* pcon)
{
    /*pcon->sz = 0;
    memset(pcon->data, 0, sizeof(pcon->data));//填充初始化，注意sizeof里的是整个数组*/
    pcon->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
    if (pcon->data == NULL)
    {
        printf("通讯录初始化失败\n");
        printf("%s", strerror(errno));
        return;
    }
    pcon->sz = 0;
    pcon->capacity = DEFAULT_SZ;
    //新增加加载之前的数据
    Load_Contact(pcon);//注意这里又新增一个函数
}

void Destroy_Contact(Contact* pcon)//注意这是一个新加的接口函数
{
    free(pcon->data);
    pcon->data = NULL;
    pcon->capacity = 0;
    pcon->sz = 0;
    printf("已经销毁通讯录!\n");
}

int Check_Capacity(Contact* pcon)//注意这是一个新加的辅助函数，这里的int是返回是否扩容成功的信息，失败返回0，成功或不需要则返回1
{
    if (pcon->sz == pcon->capacity)
    {
        PeoInfo* ptr = (PeoInfo*)realloc(pcon->data, (pcon->capacity + INC_SZ) * sizeof(PeoInfo));
        if (ptr == NULL)//没有申请成功
        {
            printf("CheckCapacity:%s\n", strerror(errno));
            return 0;
        }
        else
        {
            pcon->data = ptr;
            pcon->capacity += INC_SZ;
            printf("增容成功,当前容量为:%d\n", pcon->capacity);
            return 1;
        }
        return 1;
    }
    return 1;
}

void Add_Contact(Contact* pcon)
{
    /*if (pcon->sz == MAX_DATA)
    {
        printf("通讯录满了，无法继续存储!\n");
        return;
    }
    else//开始增加
    {*/
    if (0 == Check_Capacity(pcon))
    {
        printf("函数扩容失败\n");
        return;
    }
    else
    {
        printf("请输入名字:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].name);
        printf("请输入年龄:\n");
        scanfNumber = scanf("%d", &(pcon->data[pcon->sz].age));
        printf("请输入性别:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].sex);
        printf("请输入电话:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].tele);
        printf("请输入地址:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].addr);
        pcon->sz++;
        printf("添加成功!\n");
    }
    /*}*/
}

void Show_Contact(const Contact* pcon)
{
    int i = 0;
    printf("%-10s %-4s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
    for (i = 0; i < (pcon->sz); i++)
    {
        printf("%-10s %-4d %-5s %-12s %-30s\n", pcon->data[i].name, pcon->data[i].age, pcon->data[i].sex, pcon->data[i].tele, pcon->data[i].addr);
    }
}

static int Find_By_Name(const Contact* pcon, char name[])//内部辅助函数，不暴露给外界，加入static只能在本.c文件看到
{
    int i = 0;
    for (i = 0; i < pcon->sz; i++)
    {
        if (0 == strcmp(pcon->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}
void Dle_Contact(pContact pcon)
{
    if (pcon->sz == 0)
    {
        printf("通讯录为0，无法进行删除!\n");
        return;
    }
    //开始删除
    //1、找到要删除的联系人数据
    printf("输入要删除人的名字:\n");
    char name[MAX_NAME] = { 0 };
    scanfNumber = scanf("%s", name);
    int pos = Find_By_Name(pcon, name);
    if (pos == -1)
    {
        printf("要删除的人不存在!\n");
        return;
    }
    //2、开始正式删除联系人数据
    //需要挪动数组，类似顺序表，最后sz要--
    int i = 0;
    for (i = pos; i < pcon->sz - 1; i++)
    {
        pcon->data[i] = pcon->data[i + 1];
    }
    pcon->sz--;
    printf("删除成功！\n");
}

void Search_Contact(const pContact pcon)
{
    char name[MAX_NAME] = { 0 };
    printf("请输入要查找联系人的名字:\n");
    scanfNumber = scanf("%s", name);
    int pos = Find_By_Name(pcon, name);
    if (pos == -1)
    {
        printf("要查找的联系人不存在!\n");
    }
    else
    {
        printf("%-10s %-4s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-10s %-4d %-5s %-12s %-30s\n",
            pcon->data[pos].name,
            pcon->data[pos].age,
            pcon->data[pos].sex,
            pcon->data[pos].tele,
            pcon->data[pos].addr);
    }
}

void Modify_Contact(Contact* pcon)
{
    char name[MAX_NAME] = { 0 };
    printf("请输入要修改人的名字:\n");
    scanfNumber = scanf("%s", name);
    int pos = Find_By_Name(pcon, name);
    if (pos == -1)
    {
        printf("要修改的人不存在!\n");
        return;
    }
    //开始进行修改
    printf("请输入名字:\n");
    scanfNumber = scanf("%s", pcon->data[pos].name);
    printf("请输入年龄:\n");
    scanfNumber = scanf("%d", &(pcon->data[pos].age));
    printf("请输入性别:\n");
    scanfNumber = scanf("%s", pcon->data[pos].sex);
    printf("请输入电话:\n");
    scanfNumber = scanf("%s", pcon->data[pos].tele);
    printf("请输入地址:\n");
    scanfNumber = scanf("%s", pcon->data[pos].addr);
    printf("修改成功!\n");
}

int cmp_by_name(const void* e1, const void* e2)
{
    return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);//注意要写两层括号，避免只是临时强制转化
}

void Sort_Contact(Contact* pcon)
{
    qsort(pcon->data, pcon->sz, sizeof(PeoInfo), cmp_by_name);//要排序的数组，元素个数，一个元素大小
    printf("排序成功!\n");
}

void Save_Contact(Contact* pcon)//这个函数又是新增加的
{
    //打开文件
    FILE* pf = fopen("limou_contact.data", "wb");
    if (pf == NULL)
    {
        perror("Save_Contact::fopen");
        return 1;
    }
    //输出数据
    for (int i = 0; i < pcon->sz; i++)
    {
        fwrite(&pcon->data[i], sizeof(PeoInfo), 1, pf);
    }
    //关闭文件
    fclose(pf);
    printf("通讯录数据已保存\n");
    pf = NULL;
}