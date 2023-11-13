#pragma once
#include <iostream>
#include <cassert>

namespace limou
{
	//任务描述：
	//三元组 TupNode 结构存储某个元
	//使用 TSMatrix 链接三元组数据结构
	//根据用户输入得到两个链表结构
	//对两链表进行算术操作，最后输出矩阵结果

	//三元组结构
	template <typename ElemType>
	struct TupNode
	{
		int _row;		//该元素所处行数
		int _col;		//该元素所处列数
		ElemType _data;	//存储的非零值

		TupNode() : _row(0), _col(0), _data(ElemType()) {}
	};

	//行列式结构
	template <typename ElemType>
	class TSMatrix
	{
	public://成员函数
		//构造函数
		TSMatrix(int rows = 0, int cols = 0, int size = 0)
			: _arr(nullptr), _rows(rows), _cols(cols), _size(size)
		{
			_arr = new TupNode<ElemType>[_size];
		}
		//拷贝构造
		TSMatrix(TSMatrix<int>& tsm)
		{
			_rows = tsm._rows;
			_cols = tsm._cols;
			_size = tsm._size;
			
			_arr = new TupNode<ElemType>[_size];

			int i = 0;
			while (i < _size)
			{
				_arr[i] = tsm._arr[i];
				i++;
			}
		}
		//析构函数
		~TSMatrix()
		{
			delete[] _arr;
		}

		//添加三元组
		/*描述：一次添加一个三元组*/
		bool Push(int row, int col, int data)
		{
			int i = row - 1;
			int j = col - 1;
			if (i < _rows && j < _cols)
			{
				_arr[] = data;
			}
			return true;
		}

		//行列式相加
		/*描述：将两个链表进行相加操作*/
		TSMatrix<ElemType>& Add(const TSMatrix<ElemType>& tsm)
		{
			return *this;
		}

		//行列式相减
		/*描述：将两个链表进行相减操作*/
		TSMatrix<ElemType>& Sub(const TSMatrix<ElemType>& tsm)
		{
			return *this;
		}

		//返回行列个数
		int Rows()
		{
			return _rows;
		}
		int Cols()
		{
			return _cols;
		}

		//行列式打印
		void Print()
		{
			std::cout << "行列行数和列数为:" << _rows << "," << _cols << std::endl;
			std::cout << "其中非零元个数为:" << _size;
			for (int i = 0; i < _rows; i++)
			{
				for (int j = 0; j < _cols; j++)
				{
					;
				}
			}
		}

	private://成员变量
		TupNode<ElemType>* _arr;	//三元表
		int _rows;					//总行数
		int _cols;					//总列数
		int _size;					//总个数
	};
}
