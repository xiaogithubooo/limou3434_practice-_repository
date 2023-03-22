#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12 
#define MAX_ADDR 30
#define MAX_DATA 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.表示一个“人”结构体
typedef struct PeoInfo
{
	char name[MAX_NAME];//名字
	int age;//年龄
	char sex[MAX_SEX];//性别
	char tele[MAX_TELE];//电话
	char addr[MAX_ADDR];//地址 
}PeoInfo;

//2.表示一份“通讯录”结构体
typedef struct Contact
{
	PeoInfo data[MAX_DATA];//存放“人”的数据，这里注意到不可以使用宏放入结构体内的数组
	int sz;//实时记录通讯录的人数个数
}Contact, *pContact;//两种写法

//3.函数声明
//3.1.初始化函数
void Init_Contact(Contact* pcon);
//3.2.增加指定联系人函数
void Add_Contact(Contact* pcon);
//3.3.显示联系人信息
void Show_Contact(const Contact* pcon);
//3.4.删除联系人
void Dle_Contact(pContact pcon);
//3.5.查找联系人
void Search_Contact(const pContact pcon);
//3.6.修改联系人
void Modify_Contact(Contact* pcon);
//3.7.排序元素
void Sort_Contact(Contact* pcon);