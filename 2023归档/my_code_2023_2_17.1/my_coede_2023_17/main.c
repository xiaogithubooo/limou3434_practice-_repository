#define _CRT_SECURE_NO_WARNINGS 1
////1��������Ŀ
//int missingNumber(int* nums, int numsSize)
//{
//    int add_1 = 0;
//    int add_2 = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        add_1 += i;
//        if (i < numsSize)
//        {
//            add_2 += nums[i];
//        }
//    }
//    return add_1 - add_2;
//}
//int missingNumber(int* nums, int numsSize)
//{
//    int x = 0;
//    int i = 0;
//
//    for (i = 0; i < numsSize; i++)//��forѭ���������numsԪ�ص�����
//    {
//        x ^= nums[i];
//    }
//
//    for (i = 0; i < numsSize + 1; i++)//������������a^a=0���ҳ���ʧ������
//    {
//        x ^= i;
//    }
//    return x;
//}
////2��������Ŀ
//˼·һ��
//void rotate(int* nums, int numsSize, int k)
//{
//    while (k--)
//    {
//        int tmp = nums[numsSize - 1];//�������һ������
//        for (int end = numsSize - 2; end >= 0; --end)//��ʼ�����һ������ǰ����������ֺ���
//        {
//            nums[end + 1] = nums[end];
//        }
//        nums[0] = tmp;
//    }
//}
//���ǳ�����ʱ������
//˼·����
//void Reverse(int* nums, int left, int right)
//{
//    while (left < right)//����������ȣ�ż�������
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        ++left;
//        --right;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= numsSize)//��ֹk���������С������7��Ԫ����ת13�κ�6�εȼ�
//    {
//        k %= numsSize;
//    }
//    Reverse(nums, numsSize - k, numsSize - 1);//��벿��
//    Reverse(nums, 0, numsSize - k - 1);//ǰ�벿��
//    Reverse(nums, 0, numsSize - 1);
//}