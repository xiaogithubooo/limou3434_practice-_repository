void HeapSort_3(int* arr, int arrsize)
{
    //��Ҷ�ӽڵ㿪ʼ���ŵ������Գ�һ���ѣ������Դӵ�һ����Ҷ�ӽڵ㿪ʼ���� 
    //1.�������µ��������� 
    for (int i = ((arrsize - 1) - 1) / 2; i >= 0; i--)
    {
        AdjustDown(arr, arrsize, i);
    }
    //2.�������µ�����������
    for (int i = arrsize - 1; i > 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        AdjustDown(arr, i, 0);
    }
}
