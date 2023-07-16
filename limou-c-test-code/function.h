/** 前要说明
* 1、本项目创建时间：2023/3/4
* 2、本项目主要内容：建立在 同济大学数学系 编《工程数学：线性代数（第六册）》 书籍上实现有关线性代数的接口函数
* 3、本项目参与人员：limou3434
* 4、本项目使用语言：C语言
* 5、本项目主要目的：
* ①对于C语言的深刻理解
* ②学习巩固线性代数
* ③尝试团队合作
* ④尝试发布在GitHub上成为开源项目
*/

//定义一个可以存放行列式数据的结构体，即行列式类型
#define ROW 10
#define COL 10
typedef struct number_table
{
	int arr[ROW][COL];//行和列数据存储
	int n;//行列式阶数
}number_table;

//1、定义一个初始化行列式的函数
void function_table_initialize(number_table* table);//(传入行列式指针)

//2、定义一个可以输入输出的I/O函数
void function_table_n_IO(number_table* table, int n, int x);//(传入行列式指针, 选择“输入”或者“输出”)
