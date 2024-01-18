#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>

namespace Limou
{
	//任务描述：
	//三元组 TupNode 结构存储某个元
	//使用 TSMatrix 链接三元组数据结构
	//根据用户输入得到两个链表结构
	//对两链表进行算术操作，最后输出新链表结构

	//算法描述：
	//使用三元组来存储数据（包含该元素的“非零值、所处行数、所处列数”）
	//使用 list 即双向循环链表来存储该结构体的数据

	//三元组结构
	template <typename T>
	struct TupNode
	{
		int _row;		//该元素所处行数
		int _col;		//该元素所处列数
		T _data;		//存储的非零值

		TupNode(int row, int col, T data)//强制用户输入构造
			: _row(row), _col(col), _data(data)
		{}
	};

	//行列式结构
	template <typename T>
	class TSMatrix
	{
	public:
		void Push(const TupNode<T>& val)
		{
			_maxRow = std::max(_maxRow, val._row);
			_maxCol = std::max(_maxCol, val._col);
			_arr.push_back(val);
		}
		void Add(const TSMatrix<T>& arr)
		{
			
		}
		void sub()
		{

		}
		void Print()
		{

		}

	private://成员变量
		std::list<TupNode<T>> _arr;	//存储三元组的链表
		int _maxRow = 0;
		int _maxCol = 0;
	};
}




//typedef TupNode<ElemType> Data;
//
//	public://成员函数
//		//构造函数
//		TSMatrix(int rows = 3, int cols = 3, int capacity = 9)
//			: _arr(nullptr), _rows(rows), _cols(cols), _size(0), _capacity(capacity)
//		{
//			_arr = new Data[2];
//		}
//		//析构函数
//		~TSMatrix()
//		{
//			delete[] _arr;
//		}
//
//		//添加三元组
//		/*描述：一次添加一个三元组*/
//		bool Push(int row, int col, int data)
//		{
//			//检查扩容
//			if (_size == _capacity)
//			{
//				newCapacity = _capacity * 2;
//				Data* newArr = new Data[newCapacity];
//				while (_size--)
//				{
//					newArr->_data = _arr->_data;
//					newArr->_col = _arr->_col;
//					newArr->_row = _arr->_row;
//				}
//				delete _arr;
//				_arr = newArr;
//			}
//
//			//Push新数据
//			int i = row - 1;//用户输入 1 就是 0
//			int j = col - 1;//用户输入 1 就是 0
//			if (i < _rows && j < _cols)
//			{
//				_arr->
//
//			}
//
//			_size++;
//			return true;
//		}
//
//		//行列式相加
//		/*描述：将两个链表进行相加操作*/
//		TSMatrix<ElemType>& Add(const TSMatrix<ElemType>& tsm)
//		{
//			return *this;
//		}
//
//		//行列式相减
//		/*描述：将两个链表进行相减操作*/
//		TSMatrix<ElemType>& Sub(const TSMatrix<ElemType>& tsm)
//		{
//			return *this;
//		}
//
//		//返回行列总数
//		int Rows()
//		{
//			return _rows;
//		}
//		int Cols()
//		{
//			return _cols;
//		}
//
//		//行列式打印
//		void Print()
//		{
//			for (int i = 0; i < _rows; i++)
//			{
//				for (int j = 0; j < _cols; j++)
//				{
//					if (_arr->_row == i && _arr->_col == j)
//						std::cout << _arr->_data << " ";
//					else
//						std::cout << "0 ";
//				}
//				std::cout << '\n';
//			}
//		}