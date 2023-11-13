#include "TSMatrix.hpp"
using namespace std;
using namespace limou;
int main()
{
	int rows = 0, cols = 0, size = 0;
	int row = 0, col = 0;
	int data;//存储的数据，暂时只考虑整型

	//1.输入数据
	//1.1.行列式1
	cout << "请输入 [行列式1] 的 [rows(行数)] 和 [cols(列数)] 和 [size(非零元个数)]:\n";
	cin >> rows >> cols >> size;
	TSMatrix<int> det1(rows, cols, size);

	for (int i = 0; i < size; i++)
	{
		cout << "请输入非零元的 [row(所在行)] [col(所在列)] [data(存储元素)]:\n";
		cin >> row >> col >> data;
		det1.Push(row, col, data);
	}
	cout << "[行列式1] 输入结束\n";

	//1.2.行列式2
	cout << "请输入 [行列式2] 的 [rows(行数)] 和 [cols(列数)] 和 [size(非零元个数)]:\n";
	cin >> rows >> cols >> size;
	TSMatrix<int> det2(rows, cols, size);

	for (int i = 0; i < size; i++)
	{
		cout << "请输入非零元的 [row(所在行)] [col(所在列)] [data(存储元素)]:\n";
		cin >> row >> col >> data;
		det2.Push(row, col, data);
	}
	cout << "[行列式2] 输入结束\n";

	//2.算术运算
	TSMatrix<int> det = det1.Add(det2);
	
	//3.输出结果
	det.Print();

	return 0;
}