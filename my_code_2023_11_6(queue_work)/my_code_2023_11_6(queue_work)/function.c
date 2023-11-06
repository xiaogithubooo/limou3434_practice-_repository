#include "function.h"

int scanfNumber = 0;//接受scanf返回值，避免警告
//1.辅助函数
//辅助1：改变容量
int Check_Capacity(Contact* pcon)//这里的int是返回是否扩容成功的信息，失败返回0，成功或不需要则返回1
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
//辅助2：快排函数的回调函数
int cmp_by_name(const void* e1, const void* e2)
{
    return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);//注意要写两层括号，避免只是临时强制转化
}
//辅助3：读取上次文件的输入内容
void Load_Contact(Contact* pcon)
{
    //1.打开文件
    FILE* pf = fopen("limou_contact.data", "rb");//二进制文件
    if (pf == NULL)
    {
        perror("Load_Contact::");
        return;
    }

    //2.加载数据（利用文件指针读文件）
    PeoInfo tmp = { 0 };//人结构体，暂时存储之前旧数据
    while (fread(&tmp, sizeof(PeoInfo), 1, pf))
    {
        Check_Capacity(pcon);//查验是否扩容
        pcon->data[pcon->sz] = tmp;//结构体变量直接赋值
        pcon->sz++;
    }

    //关闭文件
    fclose(pf);
    pf = NULL;
}
//辅助4：查找名字字段对应的下标
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

//2.主体函数
//初始化函数(init)
void Init_Contact(Contact* pcon)
{
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
    Load_Contact(pcon);
}
//销毁函数(destroy)
void Destroy_Contact(Contact* pcon)//注意这是一个新加的接口函数
{
    free(pcon->data);
    pcon->data = NULL;
    pcon->capacity = 0;
    pcon->sz = 0;
    printf("已经销毁通讯录!\n");
}
//增加指定联系人函数(add)
void Add_Contact(Contact* pcon)
{
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
}
//显示联系人信息(show)
void Show_Contact(const Contact* pcon)
{
    int i = 0;
    printf("%-10s %-4s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
    for (i = 0; i < (pcon->sz); i++)
    {
        printf("%-10s %-4d %-5s %-12s %-30s\n", pcon->data[i].name, pcon->data[i].age, pcon->data[i].sex, pcon->data[i].tele, pcon->data[i].addr);
    }
}
//删除联系人(delete)
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
//查找联系人(find)
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
//修改联系人(modification)
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
//排序元素(srot)
void Sort_Contact(Contact* pcon)
{
    qsort(pcon->data, pcon->sz, sizeof(PeoInfo), cmp_by_name);//要排序的数组，元素个数，一个元素大小
    printf("排序成功!\n");
}
//存储数据到文件(save)
void Save_Contact(Contact* pcon)//这个函数又是新增加的
{
    //打开文件
    FILE* pf = fopen("limou_contact.data", "wb");
    if (pf == NULL)
    {
        perror("Save_Contact::fopen");
        return;
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