#pragma once
#include <iostream>
#include <cassert>

namespace limou
{
	//����������
	//��Ԫ�� TupNode �ṹ�洢ĳ��Ԫ
	//ʹ�� TSMatrix ������Ԫ�����ݽṹ
	//�����û�����õ���������ṹ
	//���������������������������������

	//��Ԫ��ṹ
	template <typename ElemType>
	struct TupNode
	{
		int _row;		//��Ԫ����������
		int _col;		//��Ԫ����������
		ElemType _data;	//�洢�ķ���ֵ

		TupNode() : _row(0), _col(0), _data(ElemType()) {}
	};

	//����ʽ�ṹ
	template <typename ElemType>
	class TSMatrix
	{
	public://��Ա����
		//���캯��
		TSMatrix(int rows = 0, int cols = 0, int size = 0)
			: _arr(nullptr), _rows(rows), _cols(cols), _size(size)
		{
			_arr = new TupNode<ElemType>[_size];
		}
		//��������
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
		//��������
		~TSMatrix()
		{
			delete[] _arr;
		}

		//�����Ԫ��
		/*������һ�����һ����Ԫ��*/
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

		//����ʽ���
		/*���������������������Ӳ���*/
		TSMatrix<ElemType>& Add(const TSMatrix<ElemType>& tsm)
		{
			return *this;
		}

		//����ʽ���
		/*��������������������������*/
		TSMatrix<ElemType>& Sub(const TSMatrix<ElemType>& tsm)
		{
			return *this;
		}

		//�������и���
		int Rows()
		{
			return _rows;
		}
		int Cols()
		{
			return _cols;
		}

		//����ʽ��ӡ
		void Print()
		{
			std::cout << "��������������Ϊ:" << _rows << "," << _cols << std::endl;
			std::cout << "���з���Ԫ����Ϊ:" << _size;
			for (int i = 0; i < _rows; i++)
			{
				for (int j = 0; j < _cols; j++)
				{
					;
				}
			}
		}

	private://��Ա����
		TupNode<ElemType>* _arr;	//��Ԫ��
		int _rows;					//������
		int _cols;					//������
		int _size;					//�ܸ���
	};
}
