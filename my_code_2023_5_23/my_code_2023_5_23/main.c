#define _CRT_SECURE_NO_WARNINGS 1
//利用前面写好的堆接口
void HeapSort(int* arr, int arrsize)
{
    Heap hp;
    HeapInit(&hp);//初始化
    for (int i = 0; i < arrsize; i++)
    {
        HeapPush(&hp, arr[i]);//不断插入
    }
    for (int i = 0; i < arrsize; i++)
    {
        arr[i] = HeapTop(&hp);//不断取出拷贝回原来传递过来的数组
        HeapPop(&hp);
    }
    HeapDestory(&hp);
}
int main()
{
    int arr[10] = { 1, 192, 34, 412, 32, 0, -2134, 23, 45, 89 };
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    HeapSort(arr, sizeof(arr) / sizeof(int));//堆排序
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
//但是这种比较粗糙，不是直接排序出来，而是通过拷贝再粘贴的方式，比较粗糙，效率可以，但还需要先建立一个堆，空间复杂度高

//利用前面写好的向上和向下调整算法，模拟堆的入堆和出堆
void AdjustUp(HPDataType* arr, int childi);
void AdjustDown(HPDataType* arr, int arrsize, int parenti);
void HeapSort(int* arr, int arrsize)
{
    //直接把数组内的元素数据调整为堆，因为任何数组在逻辑结构上都可以看作是一棵完全二叉树，所以我们利用这一点把原有的数组调整成堆
    //1.将根节点看作一个堆，然后将剩余的元素按照顺序一个一个插入到堆里，而插入就要写向上调整算法
    for (int i = 1; i < arrsize; i++)
    {
        AdjustUp(arr, i);
    }//2.一个循环走下来就建好了一个堆（注意我的向上调整算法是拿来建大堆的）
    //3.接下来模拟出堆的过程，将每一次生成的堆顶扔（换）到原数组的后面
    for (int i = arrsize - 1; i > 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        AdjustDown(arr, i, 0);
    }
}
int main()
{
    int arr[10] = { 1, 192, 34, 412, 32, 0, -2134, 23, 45, 89 };
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    HeapSort(arr, sizeof(arr) / sizeof(int));//堆排序
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//int function(Tree* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	if (root->left == NULL && root->right == NULL)
//	{
//		return 1;
//	}
//	return (function(root->left) + function(root->right));
//}

//int countNodes(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        return 1 + countNodes(root->left) + countNodes(root->right);
//    }
//}