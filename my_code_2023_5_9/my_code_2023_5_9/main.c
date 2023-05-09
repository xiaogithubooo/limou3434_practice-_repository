#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* BuyNode(int x)
//{
//    struct ListNode* cache = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (!cache) exit(-1);
//
//    cache->val = x;
//    cache->next = NULL;
//    return cache;
//}
//struct ListNode* addTwoNumbers(struct ListNode* list1, struct ListNode* list2)
//{
//    int number1 = 0;
//    int number2 = 0;
//    int i = 1;
//    while (list1)
//    {
//        number1 = number1 + list1->val * i;
//        list1 = list1->next;
//        i *= 10;
//    }
//    i = 1;
//    while (list2)
//    {
//        number2 = number2 + list2->val * i;
//        list2 = list2->next;
//        i *= 10;
//    }
//    int number3 = number1 + number2;
//
//    struct ListNode* list3 = BuyNode(0);
//    struct ListNode* cur = list3;
//    while (number3)
//    {
//        int val = number3 % 10;
//        struct ListNode* node = BuyNode(val);
//        cur->next = node;
//        cur = node;
//        number3 /= 10;
//    }
//    return list3->next;
//}
//void test(void)
//{
//    struct ListNode a1;
//    struct ListNode a2;
//    struct ListNode a3;
//    a1.val = 2;
//    a2.val = 4;
//    a3.val = 3;
//    a1.next = &a2;
//    a2.next = &a3;
//    a3.next = NULL;
//
//    struct ListNode b1;
//    struct ListNode b2;
//    struct ListNode b3;
//    b1.val = 5;
//    b2.val = 6;
//    b3.val = 4;
//    b1.next = &b2;
//    b2.next = &b3;
//    b3.next = NULL;
//
//    addTwoNumbers(&a1, &b1);
//}

int main()
{
    char ch = 0;
    printf("%zd\n", sizeof(ch));
    printf("%zd\n", sizeof(~ch));
    printf("%zd\n", sizeof(ch >> 1));
    printf("%zd\n", sizeof(ch << 1));
    printf("%zd\n", sizeof(!ch));
    return 0;
}