void HeapSort_3(int* arr, int arrsize)
{
    //从叶子节点开始倒着调整（自成一个堆），所以从第一个非叶子节点开始调整 
    //1.利用向下调整来建堆 
    for (int i = ((arrsize - 1) - 1) / 2; i >= 0; i--)
    {
        AdjustDown(arr, arrsize, i);
    }
    //2.利用向下调整法来排序
    for (int i = arrsize - 1; i > 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        AdjustDown(arr, i, 0);
    }
}
