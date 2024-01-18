/** 前要说明
* 1、本项目创建时间：2023/3/4
* 2、本项目主要内容：建立在 同济大学数学系 编《工程数学：线性代数（第六册）》 书籍上实现有关线性代数的接口函数
* 3、本项目参与人员：limou3434
* 4、本项目使用语言：C语言
* 5、本项目主要目的：
* （1）对于C语言的深刻理解
* （2）学习巩固线性代数
* （3）尝试团队合作，学习使用git
* （4）尝试发布在GitHub上成为开源项目
*/
//0.1.头文件声明
#include <stdio.h>
#include <math.h>
//0.2.宏定义
#define ROW 10
#define COL 10
#define NUM 10
//0.3.定义一个可以存放行列式数据的结构体，即行列式类型
typedef struct number_table
{
	int arr[ROW][COL];//行和列数据存储
	int n;//行列式阶数
}number_table;
//0.4.定义一个全排列结构体
typedef struct number_arrary
{
	int arr[NUM];
	int n;
}number_arrary;

//1.定义一个初始化行列式的函数
void FunctionInitialize_table(number_table* table);//(传入行列式指针)

//2.定义一个输入行列式的函数
void FunctionInput_table(number_table* table);//(传入行列式指针)

//3.定义一个输出行列式的函数
void FunctionOutput_table(number_table* table);//(传入行列式指针)

//4.1.定义一个计算二阶、三阶行列式的函数
void FunctionCalculate1_table(number_table* table);

//4.2.定义一个计算高阶行列式的函数

//5.定义一个计算逆序数的函数
void FunctionInverseNumber_arrary(number_arrary* arrary);

//6.定义一个输入排列的输入函数
void FunctionInput_arrary(number_arrary* arrary);
