#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20     //name�ֶ����ֵ
#define MAX_SEX 5       //sex�ֶ����ֵ
#define MAX_TELE 12     //tele�ֶ����ֵ
#define MAX_ADDR 30     //addr�ֶ����ֵ
#define DEFAULT_SZ 3    //Ĭ������3����ע�����������ӵĺ�
#define INC_SZ 2        //ÿ�η���������ע�����������ӵĺ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//1.��ʾһ�����ˡ��ṹ��
typedef struct PeoInfo
{
    char name[MAX_NAME];//����
    int  age;           //����
    char sex[MAX_SEX];  //�Ա�
    char tele[MAX_TELE];//�绰
    char addr[MAX_ADDR];//��ַ
}PeoInfo;

//2.��ʾһ�ݡ�ͨѶ¼���ṹ��
typedef struct Contact
{
    PeoInfo* data;      //ָ��̬�ڴ��ָ��
    int      sz;        //ʵʱ��¼ͨѶ¼����������
    int      capacity;  //����ͨѶ¼��ǰ����
}Contact, *pContact;

//3.��������
//3.1.��ʼ������(init)
void Init_Contact(Contact* pcon);
//3.2.���ٺ���(destroy)
void Destroy_Contact(Contact* pcon);
//3.3.����ָ����ϵ�˺���(add)
void Add_Contact(Contact* pcon);
//3.4.��ʾ��ϵ����Ϣ(show)
void Show_Contact(const Contact* pcon);
//3.5.ɾ����ϵ��(delete)
void Dle_Contact(pContact pcon);
//3.6.������ϵ��(find)
void Search_Contact(const pContact pcon);
//3.7.�޸���ϵ��(modification)
void Modify_Contact(Contact* pcon);
//3.8.����Ԫ��(srot)
void Sort_Contact(Contact* pcon);
//3.9.�洢���ݵ��ļ�(save)
void Save_Contact(Contact* pcon);