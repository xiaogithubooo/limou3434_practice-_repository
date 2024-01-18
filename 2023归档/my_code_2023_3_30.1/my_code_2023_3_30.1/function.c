#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int scanfNumber = 0;

int Check_Capacity(Contact* pcon);//���������������Ҫ�õ����Ա�����ǰ������һ��
void Load_Contact(Contact* pcon)//ע������������һ������
{
    //���ļ�
    FILE* pf = fopen("limou_contact.data", "rb");
    if (pf == NULL)
    {
        perror("Load_Contact::");
        return 1;
    }
    //�������ݣ����ļ���
    PeoInfo tmp = { 0 };//��ʱ�洢֮ǰ������
    while (fread(&tmp, sizeof(PeoInfo), 1, pf))
    {
        Check_Capacity(pcon);
        pcon->data[pcon->sz] = tmp;//C������ṹ�����ֱ�Ӹ�ֵ������
        pcon->sz++;
    }
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
}
void Init_Contact(Contact* pcon)
{
    /*pcon->sz = 0;
    memset(pcon->data, 0, sizeof(pcon->data));//����ʼ����ע��sizeof�������������*/
    pcon->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
    if (pcon->data == NULL)
    {
        printf("ͨѶ¼��ʼ��ʧ��\n");
        printf("%s", strerror(errno));
        return;
    }
    pcon->sz = 0;
    pcon->capacity = DEFAULT_SZ;
    //�����Ӽ���֮ǰ������
    Load_Contact(pcon);//ע������������һ������
}

void Destroy_Contact(Contact* pcon)//ע������һ���¼ӵĽӿں���
{
    free(pcon->data);
    pcon->data = NULL;
    pcon->capacity = 0;
    pcon->sz = 0;
    printf("�Ѿ�����ͨѶ¼!\n");
}

int Check_Capacity(Contact* pcon)//ע������һ���¼ӵĸ��������������int�Ƿ����Ƿ����ݳɹ�����Ϣ��ʧ�ܷ���0���ɹ�����Ҫ�򷵻�1
{
    if (pcon->sz == pcon->capacity)
    {
        PeoInfo* ptr = (PeoInfo*)realloc(pcon->data, (pcon->capacity + INC_SZ) * sizeof(PeoInfo));
        if (ptr == NULL)//û������ɹ�
        {
            printf("CheckCapacity:%s\n", strerror(errno));
            return 0;
        }
        else
        {
            pcon->data = ptr;
            pcon->capacity += INC_SZ;
            printf("���ݳɹ�,��ǰ����Ϊ:%d\n", pcon->capacity);
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
        printf("ͨѶ¼���ˣ��޷������洢!\n");
        return;
    }
    else//��ʼ����
    {*/
    if (0 == Check_Capacity(pcon))
    {
        printf("��������ʧ��\n");
        return;
    }
    else
    {
        printf("����������:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].name);
        printf("����������:\n");
        scanfNumber = scanf("%d", &(pcon->data[pcon->sz].age));
        printf("�������Ա�:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].sex);
        printf("������绰:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].tele);
        printf("�������ַ:\n");
        scanfNumber = scanf("%s", pcon->data[pcon->sz].addr);
        pcon->sz++;
        printf("��ӳɹ�!\n");
    }
    /*}*/
}

void Show_Contact(const Contact* pcon)
{
    int i = 0;
    printf("%-10s %-4s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
    for (i = 0; i < (pcon->sz); i++)
    {
        printf("%-10s %-4d %-5s %-12s %-30s\n", pcon->data[i].name, pcon->data[i].age, pcon->data[i].sex, pcon->data[i].tele, pcon->data[i].addr);
    }
}

static int Find_By_Name(const Contact* pcon, char name[])//�ڲ���������������¶����磬����staticֻ���ڱ�.c�ļ�����
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
        printf("ͨѶ¼Ϊ0���޷�����ɾ��!\n");
        return;
    }
    //��ʼɾ��
    //1���ҵ�Ҫɾ������ϵ������
    printf("����Ҫɾ���˵�����:\n");
    char name[MAX_NAME] = { 0 };
    scanfNumber = scanf("%s", name);
    int pos = Find_By_Name(pcon, name);
    if (pos == -1)
    {
        printf("Ҫɾ�����˲�����!\n");
        return;
    }
    //2����ʼ��ʽɾ����ϵ������
    //��ҪŲ�����飬����˳������szҪ--
    int i = 0;
    for (i = pos; i < pcon->sz - 1; i++)
    {
        pcon->data[i] = pcon->data[i + 1];
    }
    pcon->sz--;
    printf("ɾ���ɹ���\n");
}

void Search_Contact(const pContact pcon)
{
    char name[MAX_NAME] = { 0 };
    printf("������Ҫ������ϵ�˵�����:\n");
    scanfNumber = scanf("%s", name);
    int pos = Find_By_Name(pcon, name);
    if (pos == -1)
    {
        printf("Ҫ���ҵ���ϵ�˲�����!\n");
    }
    else
    {
        printf("%-10s %-4s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
    printf("������Ҫ�޸��˵�����:\n");
    scanfNumber = scanf("%s", name);
    int pos = Find_By_Name(pcon, name);
    if (pos == -1)
    {
        printf("Ҫ�޸ĵ��˲�����!\n");
        return;
    }
    //��ʼ�����޸�
    printf("����������:\n");
    scanfNumber = scanf("%s", pcon->data[pos].name);
    printf("����������:\n");
    scanfNumber = scanf("%d", &(pcon->data[pos].age));
    printf("�������Ա�:\n");
    scanfNumber = scanf("%s", pcon->data[pos].sex);
    printf("������绰:\n");
    scanfNumber = scanf("%s", pcon->data[pos].tele);
    printf("�������ַ:\n");
    scanfNumber = scanf("%s", pcon->data[pos].addr);
    printf("�޸ĳɹ�!\n");
}

int cmp_by_name(const void* e1, const void* e2)
{
    return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);//ע��Ҫд�������ţ�����ֻ����ʱǿ��ת��
}

void Sort_Contact(Contact* pcon)
{
    qsort(pcon->data, pcon->sz, sizeof(PeoInfo), cmp_by_name);//Ҫ��������飬Ԫ�ظ�����һ��Ԫ�ش�С
    printf("����ɹ�!\n");
}

void Save_Contact(Contact* pcon)//����������������ӵ�
{
    //���ļ�
    FILE* pf = fopen("limou_contact.data", "wb");
    if (pf == NULL)
    {
        perror("Save_Contact::fopen");
        return 1;
    }
    //�������
    for (int i = 0; i < pcon->sz; i++)
    {
        fwrite(&pcon->data[i], sizeof(PeoInfo), 1, pf);
    }
    //�ر��ļ�
    fclose(pf);
    printf("ͨѶ¼�����ѱ���\n");
    pf = NULL;
}