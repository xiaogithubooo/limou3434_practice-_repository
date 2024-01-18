#pragma once
#define _CRT_SECURE_NO_WARNINGS 1   //防止在VS2022下无法使用scanf()
#define MAX_NAME 20                 //字段最大值
#define MAX_SEX 5                   //字段最大值
#define MAX_TELE 12                 //字段最大值
#define MAX_ADDR 30                 //字段最大值
#define MAX_DATA 100                //字段最大值
#define DEFAULT_SZ 3                //默认容量3个，注意这是新增加的宏
#define INC_SZ 2                    //每次翻倍次数，注意这是新增加的宏
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//1.表示一个“人”结构体
typedef struct PeoInfo
{
    char name[MAX_NAME];    //名字
    int age;                //年龄
    char sex[MAX_SEX];      //性别
    char tele[MAX_TELE];    //电话
    char addr[MAX_ADDR];    //地址
}PeoInfo;

//2.表示一份“通讯录”结构体
typedef struct Contact
{
    PeoInfo* data;      //指向动态内存的指针
    int sz;             //实时记录通讯录的人数个数
    int capacity;       //计入通讯录当前容量
}Contact, * pContact;   //两种写法

//3.函数声明
//3.1.1.初始化函数
void Init_Contact(Contact* pcon);
//3.1.2.销毁函数
void Destroy_Contact(Contact* pcon);
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
//3.8.存储数据到文件
void Save_Contact(Contact* pcon);