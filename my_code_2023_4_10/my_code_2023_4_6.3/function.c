#include "function.h" 

//# 1.��������
//> 1.1.ֱ�Ӳ�������
/*����ԭ������һ���������򣬺����������ǰ�������������򣬼���[0, end]������ģ���end + 1��λ�õ�ֵ�����ȥ����[0, end + 1]Ҳ����*/
/*�����ܽ᣺����forѭ����¼��ÿ������������е����һ���±꣬��¼Ҫ�²�������ݣ����������������жԱȣ�����ԭ��������ݵĿռ��������1��ռ��У�Ų�����б�֤��һ����λ�����²����*/
/*����ʱ�䣺��������Ų������Ϊ(1+2+3+��(n-1))���ɵȲ����й�ʽ���ʱ�临�Ӷ�ΪO(n^2)
		   �������ã�˳�������ʱ��ʱ�临�Ӷ�ΪO(n)*/
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)//���ѭ�������þ��Ǳ�֤end�����ҵ��Ѿ������еĵ����һ���±꣬ע����i < n - 1��������i < n
	{
		int end = i;//���ϸ����µ�end
		int tmp = a[end + 1];//��¼Ҫ�²��������

		//��ʼ����������
		while (end >= 0)//��������ֹ��������һ��end����-1�������û����һ������a[end+1]��ҪС��������������ĳ����a[end+1]��ҪС��
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;//֮����Ų����������Ϊ���Ȳ���Ҫ����������룬������Ų��[ a[0],a[end+1] ]�����ݣ���֤����һ��λ�ò����²��������
	}
}
//> 1.2.ϣ������
/*����ԭ������Ԥ����Ȼ����ֱ�Ӳ�����������Ԥ����Ҫ�������򣩣�����ÿ���������м����gap-1�����ֳַ�һ�飬��ÿһ���Ƚ���ֱ�Ӳ���������ʹ��gap��С������ֱ��Ԥ�������gapԽ��Ԥ����Խ���ӽ����򣬵��Ǵ��������Խ�쵽���棻gapԽС���۷�֮��ֱ��gapΪ1������ֱ�Ӳ����������Ҳ���������ֱ�Ӳ��������ڴ��������1�ĵط�ȫ���滻��gap*/
/*�����ܽ᣺��*/
/*����ʱ�䣺��gap�ڼ��ٵ�ʱ�򣬳��Զ��ٸ�2��ѭ���˶��ٴΣ�����Ϊx�Σ���ô1 == n / (2^x)����ѭ����x == log(2)N�Σ�����ǳ���3����O(log(3)N)��
		   �ڵ�gap����ʱ��ڶ���ѭ�����������O(n)����gap��С��ʱ��ڶ���ѭ��Ҳ���ӽ�������O(n)
		   ����������ʱ�临�Ӷ�ΪO(log(2)N*N)������ƽ��ΪO(N*1.3)
		   */
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//������gap��С������2�����ս������1��0�����gap��Ϊ1����ֱ��ѡ�����򣨶�gap�ļ��ٷ�ʽ�кܶ��֣�����gap = gap / 3 + 1������1��Ϊ�˱������gap==0�������
		//gap > 1����Ԥ����ʹ�ýӽ�����
		//gap == 1����ֱ�Ӳ�������

		for (int i = 0; i < n - gap; ++i)//����ѭ����Ƹ���������������ݵ�ÿһ��ֱ�Ӳ�������ͬʱ���У�ֱ�����ͬʱ�������һ��ֱ�Ӳ�������
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//# 2.ѡ������
//> 2.1.ֱ��ѡ������˫ָ���Ż��汾������ͨ��ֱ��ѡ������Ч�ʵ�������
/*����ԭ����*/
/*�����ܽ᣺��*/
/*����ʱ�䣺���ۺû�����O(n^2)��Ч���Ƚϲ�*/
//������������������
void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min_i = begin;
		int max_i = begin;

		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[min_i])
			{
				min_i = i;
			}
			if (a[i] > a[max_i])
			{
				max_i = i;
			}
		}
		Swap(&a[begin], &a[min_i]);
		if (begin == max_i)//��������ǡ���ڿ�ͷ������ǰ��Ļ������Ὣmax_x������ԭ�е����ֵ�ı䣬�����Ҫ�����ֵ������������
		{
			max_i = min_i;
		}
		Swap(&a[max_i], &a[end]);
		++begin;
		--end;
	}
}
//> 2.2.������
/*����ԭ����һ��Ҫ������������Ϊһ����ȫ��������Ȼ���������н��ѣ���ѻ�С�ѣ���ʹ�������µ����㷨�������Ҫ���С�ѣ���ǰ��������С������С�ѣ�ʹ�����µ����㷨�Ϳ��Ա��С�ѣ���ɴ��Ҳ���ƣ���*/
/*�����ܽ᣺��*/
/*����ʱ�䣺���µ����㷨�����������ĸ߶ȴΡ������ʱ�临�Ӷ���O(log(2)n)������������������Ƶ��Ƚϸ��ӡ����Ժ�����*/
//��������������������ǰ���ж��壩
void Swap(int* a, int* b);
//�������������µ����㷨
void AdjustDwon(int* a, int n, int root)//������һ������ָ��������С�͸�һ�����ڵ���±꣬�ú������������������Ѿ��Ǵ��
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ��������
	while (child < n)//�����Գ����洢�������С���߳���Ҷ�ڵ�
	{
		//������ѡ���ϴ�ĺ���
		if (child + 1 < n && a[child + 1] > a[child])//������ӱȽϴ󣬲��Ҳ���ֻ��һ�����ӵ�����½�����䣨�����Ǵ������������С�Ѿ�Ҫ�ĳɡ�<����
		{
			child += 1;//����Һ�������
		}
		if (a[child] > a[parent])//������׽ڵ�Ƚ�С�ͺͽϴ��ӽڵ���н����������Ǵ��������ĳ�С�Ѿ�Ҫ�ĳɡ�<����
		{
			Swap(&a[child], &a[parent]);

			//�����µĸ��ڵ��Ĭ����ڵ� 
			parent = child;
			child = parent * 2 + 1;
		}
		else//˵������������С���ˣ����ü����ˣ�ֱ�������Ϳ���
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//�������µ������������
	for (int i = ((n - 1) - 1) / 2; i >= 0; --i)//�ȴ���������ҵ���һ����Ҷ�ӽڵ�ģ�Ȼ���ȶ��������µ���������һֱ��ǰ���ߣ������нڵ㶼����һ�����µ�������ע������i�ĳ�ʼֵ���������ӻ����Һ��Ӷ������õģ�����������ϵ��ʽ���ƾͱ����һ����ʽ��
	{
		AdjustDwon(a, n, i);
	}

	//ʹ�ý�������ų�����ȡ����ѵĸ��ŵ��������ĩβ
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//������ԭ���洢��a[0]λ�õ����ݲ��ټ�¼������
		AdjustDwon(a, end, 0);//ʹ�ôδ������ɸ��ڵ�
		--end;
	}
}

//# 3.��������
//> 3.1.ð������
/*����ԭ����*/
/*�����ܽ᣺��ֱ�Ӳ���ȣ�ֱ�Ӳ����*/
/*����ʱ�䣺��*/
//��������������������ǰ���ж��壩
void Swap(int* a, int* b);
void BubbleSort(int* a, int n)
{
	int exchange = 0;
	for (int j = 0; j < n; j++)//����ĳ�while���Ʊ߽綼��
	{
		for (int i = 1; i < n - j; ++i)//д�����������дһ�α������������Ƕ�Σ�����Ҫע��Խ�������
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)//���û�з���������˵�������Ѿ�������ģ�����Ҫ�ڱȽ���
		{
			break;
		}
	}
}
//> 3.2.��������
//3.2.1.�ڿӷ�
/*����ԭ����*/
/*�����ܽ᣺�����Ե�ʱ��Ͳ�Ҫд����ȡ�к�С�����Ż��ˣ��ȽϺķ�ʱ��*/
/*����ʱ�䣺O(N*log(2)N)��������������ģ�˳�������*/
//3.2.1.1.����һ�Σ���ָ���ڿӷ���ֻ������ϰʹ�ã�
void PartSort_0(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int pivot = begin;
	int key = a[begin];

	while (begin < end)
	{
		//�ұ���С�����ݣ����ҷ������
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];//����С���ݷ��������Լ�����µĿ�
		pivot = end;

		//����Ҵ�����ݣ����ҷ����ұ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pivot] = a[begin];//���ϴ����ݷ��������Լ�����µĿ�
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
}
//3.2.1.2.��ָ���ڿӷ�
//��������������ȡ�з�
int GetMidIndex(int* a, int left_begin, int right_end)
{
	int mid = (left_begin + right_end) >> 1;//ȡƽ��ֵ
	if (a[left_begin] < a[mid])
	{
		if (a[mid] < a[right_end])
		{
			return mid;
		}
		else if (a[left_begin] > a[right_end])
		{
			return left_begin;
		}
		else
		{
			return right_end;
		}
	}
	else//a[left_begin] > a[mid]
	{
		if (a[mid] > a[right_end])
		{
			return mid;
		}
		else if (a[left_begin] < a[right_end])
		{
			return left_begin;
		}
		else
		{
			return right_end;
		}
	}
}
int PartSort_1(int* a, int left_begin, int right_end)
{
	int index = GetMidIndex(a, left_begin, right_end);//����ȡ�з�����֤�����������е�ʱ����������������һ���±�
	Swap(&a[left_begin], &a[index]);

	int begin = left_begin;
	int end = right_end;

	int pivot = begin;//��λ
	int key = a[begin];//key��ѡȡ�ж�����������������ֱ��ѡȡ��һ��ֵ���������������ܲ������ȡ�м�ֵ����֤��һ������������������Сֵ�������ֵ�����⿴������

	while (begin < end)
	{
		//�ұ���С�����ݣ����ҷ������
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];//����С���ݷ��������Լ�����µĿ�
		pivot = end;

		//����Ҵ�����ݣ����ҷ����ұ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pivot] = a[begin];//���ϴ����ݷ��������Լ�����µĿ�
		pivot = begin;
	}
	//�����Ŀӷ���key
	pivot = begin;
	a[pivot] = key;
	return pivot;//�Żؿ�
}
//3.2.1.3.����˫ָ���ڿӷ�
int PartSort_2(int* a, int left_begin, int right_end)
{
	int index = GetMidIndex(a, left_begin, right_end);//ʹ������ȡ�з�
	Swap(&a[left_begin], &a[index]);

	int begin = left_begin;
	int end = right_end;
	int keyi = begin;

	while (begin < end)
	{
		//����ʼ�ҵ���keyiС��
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		//���ҿ�ʼ�ҵ���keyi���
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return begin;
}
//3.2.2.ǰ��ָ�뷨
int PartSort_3(int* a, int left_begin, int right_end)
{
	int index = GetMidIndex(a, left_begin, right_end);
	Swap(&a[left_begin], &a[index]);

	int keyi = left_begin;//ѡ��key���±�

	int prev = left_begin;//ǰָ��
	int cur = left_begin + 1;//��ָ��
	while (cur <= right_end)
	{
		if ((a[cur] < a[keyi]) && (++prev!= cur))//����if���ڶ����߼����ʽ��Ϊ�˱���prev�ʹ���ͬһ��λ��Ҳ���������⣨����[3],1,2,4,0,4��������ͻᷢ���Լ����Լ������������
		{
			//++prev;//����ط������ж������Ѿ�д�ˣ����ԾͲ�д�ˣ����ɾ����if����еڶ�������Ҫ�ӻ���һ��
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

//���ź�������
void QuickSort(int* a, int left_begin, int right_end)//�����ǵ�������һ�����ָ�������
{
	if (left_begin >= right_end)//ֻ��һ��Ԫ�����Ծ�ֱ�ӷ���
	{
		return;
	}

	//int keyIndex = PartSort_1(a, left_begin, right_end);//��ָ���ڿӷ�
	//int keyIndex = PartSort_2(a, left_begin, right_end);//˫ָ���ڿӷ�
	int keyIndex = PartSort_3(a, left_begin, right_end);//ǰ��ָ���ڿӷ�

	//������һ�εݹ飬�±�ͻ��[left_brgin, right_end]���[left_begin, keyIndex - 1] keyIndex [keyIndex + 1, right_end]
	//�ٿ���û���Ż��İ汾
	//QuickSort(a, left_begin, keyIndex - 1);
	//QuickSort(a, keyIndex + 1, right_end);
	
	//�������ǶԿ��ŵ�һ���Ż���С�����Ż����жϵ�������ĳ��ȣ�̫С�Ͳ��ÿ����ˣ�������С��10�����Ի�����ֵ������Ҫ��������������ֵ����Ȼ����п��ܻ��˻���ֱ�Ӳ������򣩣����ǿ����Ż�Ч��������C++�ڲ����˴��10�������ӡ���
	if ((keyIndex - 1) - (left_begin) > 10)
	{
		QuickSort(a, left_begin, keyIndex - 1);
	}
	else//�����ŵ���ϸ�������ʱ��Ϳ��������������㷨�����򣬱��ⲻ�ϵĺ���ջ֡Ӱ��Ч��
	{
		//ѡֱ�Ӳ�������ȽϺ�
		InsertSort(a + left_begin, ((keyIndex - 1) - (left_begin) + 1));//ע�������д��
	}
	if ((right_end - (keyIndex + 1)) > 10)
	{
		QuickSort(a, keyIndex + 1, right_end);
	}
	else
	{
		InsertSort(a + keyIndex + 1, ((right_end) - (keyIndex + 1) + 1));//ע�������д��
	}
}


//# 4.�鲢����
//> 4.1.�鲢����
/*����ԭ����*/
/*�����ܽ᣺*/
/*����ʱ�䣺*/
//�����������Ӻ���
void _MergeSort(int* a, int left_begin, int right_end, int* tmp)
{
	if (left_begin > right_end)
		return;
	int mid = (left_begin + right_end) >> 1;//��ƽ��ֵ
	//����[left_begin, mid][mid + 1, right_end]�����ǾͿ�ʼ�鲢
	_MergeSort(a, left_begin, mid, tmp);
	_MergeSort(a, mid + 1, right_end, tmp);

	int begin1 = left_begin, end1 = mid;
	int begin2 = mid + 1, end2 = right_end;
	int index = left_begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//����ѭ����������������С��һ������һ����һ����û����β�����ʱ��ѻ�û����β���Ǹ��������������ȫ�����������������������ѭ��ֻ��ִ��һ��
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//�����Ҫ��malloc���������ݿ�����ȥ���������ֻ�Ǹ����洢�ģ�
	for (int i = left_begin; i <= right_end; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
