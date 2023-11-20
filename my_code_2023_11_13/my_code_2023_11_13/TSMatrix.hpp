#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>

namespace Limou
{
	//����������
	//��Ԫ�� TupNode �ṹ�洢ĳ��Ԫ
	//ʹ�� TSMatrix ������Ԫ�����ݽṹ
	//�����û�����õ���������ṹ
	//���������������������������������ṹ

	//�㷨������
	//ʹ����Ԫ�����洢���ݣ�������Ԫ�صġ�����ֵ������������������������
	//ʹ�� list ��˫��ѭ���������洢�ýṹ�������

	//��Ԫ��ṹ
	template <typename T>
	struct TupNode
	{
		int _row;		//��Ԫ����������
		int _col;		//��Ԫ����������
		T _data;		//�洢�ķ���ֵ

		TupNode(int row, int col, T data)//ǿ���û����빹��
			: _row(row), _col(col), _data(data)
		{}
	};

	//����ʽ�ṹ
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

	private://��Ա����
		std::list<TupNode<T>> _arr;	//�洢��Ԫ�������
		int _maxRow = 0;
		int _maxCol = 0;
	};
}




//typedef TupNode<ElemType> Data;
//
//	public://��Ա����
//		//���캯��
//		TSMatrix(int rows = 3, int cols = 3, int capacity = 9)
//			: _arr(nullptr), _rows(rows), _cols(cols), _size(0), _capacity(capacity)
//		{
//			_arr = new Data[2];
//		}
//		//��������
//		~TSMatrix()
//		{
//			delete[] _arr;
//		}
//
//		//�����Ԫ��
//		/*������һ�����һ����Ԫ��*/
//		bool Push(int row, int col, int data)
//		{
//			//�������
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
//			//Push������
//			int i = row - 1;//�û����� 1 ���� 0
//			int j = col - 1;//�û����� 1 ���� 0
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
//		//����ʽ���
//		/*���������������������Ӳ���*/
//		TSMatrix<ElemType>& Add(const TSMatrix<ElemType>& tsm)
//		{
//			return *this;
//		}
//
//		//����ʽ���
//		/*��������������������������*/
//		TSMatrix<ElemType>& Sub(const TSMatrix<ElemType>& tsm)
//		{
//			return *this;
//		}
//
//		//������������
//		int Rows()
//		{
//			return _rows;
//		}
//		int Cols()
//		{
//			return _cols;
//		}
//
//		//����ʽ��ӡ
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