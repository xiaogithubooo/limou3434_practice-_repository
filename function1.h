/** ǰҪ˵��
* 1������Ŀ����ʱ�䣺2023/3/4
* 2������Ŀ��Ҫ���ݣ������� ͬ�ô�ѧ��ѧϵ �ࡶ������ѧ�����Դ����������ᣩ�� �鼮��ʵ���й����Դ����Ľӿں���
* 3������Ŀ������Ա��limou3434
* 4������Ŀʹ�����ԣ�C����
* 5������Ŀ��ҪĿ�ģ�
* ��1������C���Ե�������
* ��2��ѧϰ�������Դ���
* ��3�������ŶӺ�����ѧϰʹ��git
* ��4�����Է�����GitHub�ϳ�Ϊ��Դ��Ŀ
*/
//0.1.ͷ�ļ�����
#include <stdio.h>
#include <math.h>
//0.2.�궨��
#define ROW 10
#define COL 10
#define NUM 10
//0.3.����һ�����Դ������ʽ���ݵĽṹ�壬������ʽ����
typedef struct number_table
{
	int arr[ROW][COL];//�к������ݴ洢
	int n;//����ʽ����
}number_table;
//0.4.����һ��ȫ���нṹ��
typedef struct number_arrary
{
	int arr[NUM];
	int n;
}number_arrary;

//1.����һ����ʼ������ʽ�ĺ���
void FunctionInitialize_table(number_table* table);//(��������ʽָ��)

//2.����һ����������ʽ�ĺ���
void FunctionInput_table(number_table* table);//(��������ʽָ��)

//3.����һ���������ʽ�ĺ���
void FunctionOutput_table(number_table* table);//(��������ʽָ��)

//4.1.����һ��������ס���������ʽ�ĺ���
void FunctionCalculate1_table(number_table* table);

//4.2.����һ������߽�����ʽ�ĺ���

//5.����һ�������������ĺ���
void FunctionInverseNumber_arrary(number_arrary* arrary);

//6.����һ���������е����뺯��
void FunctionInput_arrary(number_arrary* arrary);
