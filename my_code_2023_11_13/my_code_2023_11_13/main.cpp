#include "TSMatrix.hpp"
using namespace std;
using namespace limou;
int main()
{
	int rows = 0, cols = 0, size = 0;
	int row = 0, col = 0;
	int data;//�洢�����ݣ���ʱֻ��������

	//1.��������
	//1.1.����ʽ1
	cout << "������ [����ʽ1] �� [rows(����)] �� [cols(����)] �� [size(����Ԫ����)]:\n";
	cin >> rows >> cols >> size;
	TSMatrix<int> det1(rows, cols, size);

	for (int i = 0; i < size; i++)
	{
		cout << "���������Ԫ�� [row(������)] [col(������)] [data(�洢Ԫ��)]:\n";
		cin >> row >> col >> data;
		det1.Push(row, col, data);
	}
	cout << "[����ʽ1] �������\n";

	//1.2.����ʽ2
	cout << "������ [����ʽ2] �� [rows(����)] �� [cols(����)] �� [size(����Ԫ����)]:\n";
	cin >> rows >> cols >> size;
	TSMatrix<int> det2(rows, cols, size);

	for (int i = 0; i < size; i++)
	{
		cout << "���������Ԫ�� [row(������)] [col(������)] [data(�洢Ԫ��)]:\n";
		cin >> row >> col >> data;
		det2.Push(row, col, data);
	}
	cout << "[����ʽ2] �������\n";

	//2.��������
	TSMatrix<int> det = det1.Add(det2);
	
	//3.������
	det.Print();

	return 0;
}