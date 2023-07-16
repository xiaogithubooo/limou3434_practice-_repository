//反转链表：https://leetcode.cn/problems/reverse-linked-list/
//1、直接反转法
struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;

    while(n2)//当n2为空指针停止判断
    {
        n2->next = n1;//只改动一条线
        
        n1 = n2;
        n2 = n3;
        if(n3)
        {
            n3 = n3->next;//避免只有一个结点的时候发生空指针解引用
        }
    }
    return n1;
}
//2、节点头插法
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;
    while(cur)
    {
        struct ListNode* next = cur->next;

        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

//链表的中间节点：https://leetcode.cn/problems/middle-of-the-linked-list/
//快慢指针
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next)//注意由于短路性，顺序不能颠倒，否则有可能发生空指针解引用
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//合并两个有序链表：https://leetcode.cn/problems/merge-two-sorted-lists/
//方法一/*** Definition for singly-linked list.* struct ListNode {*     int val;*     struct ListNode *next;* };*/struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){    //1、避免空链表    if(list1 == NULL)        return list2;    if(list2 == NULL)        return list1;    //2、非空链表    struct ListNode* head = NULL;//指向头节点的指针，方便返回这个整合后的链表    struct ListNode* tail = NULL;//指向尾节点的指针    while(list1 != NULL && list2 != NULL)//只要list1和list2没有到结尾就一直走下去    {        if(list1->val < list2->val)        {            if(tail == NULL)            {                head = tail = list1;            }            else            {                tail->next = list1;                tail = tail->next;//将尾指针挪后            }            list1 = list1->next;        }        else        {            if(tail == NULL)            {                head = tail = list2;            }            else            {                tail->next = list2;                tail = tail->next;//将尾指针挪后            }            list2 = list2->next;        }    }    //3、如果经过上述步骤还有链表有剩余元素，就直接接到后面，不必处理（本来就有序）    if(list1)    {        tail->next = list1;    }    if(list2)    {        tail->next = list2;    }    return head;}

//方法二：先取一个做头节点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //1、避免空链表
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;


    //2、非空链表
    struct ListNode* head = NULL;//指向头节点的指针，方便返回这个整合后的链表
    struct ListNode* tail = NULL;//指向尾节点的指针

    if(list1->val < list2->val)//不管如何先有一个头结点
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }

    while(list1 != NULL && list2 != NULL)//只要list1和list2没有到结尾就一直走下去
    {
        if(list1->val < list2->val)
        {
            /*if(tail == NULL)
            {
                head = tail = list1;
            }
            else
            {*/
                tail->next = list1;
                /*tail = tail->next;//将尾指针挪后
            }*/
            list1 = list1->next;
        }
        else
        {
            /*if(tail == NULL)
            {
                head = tail = list2;
            }
            else
            {*/
                tail->next = list2;
                /*tail = tail->next;//将尾指针挪后
            }*/
            list2 = list2->next;
        }

        tail = tail->next;
    }
    //3、如果经过上述步骤还有链表有剩余元素，就直接接到后面，不必处理（本来就有序）
    if(list1)
    {
        tail->next = list1;
    }
    if(list2)
    {
        tail->next = list2;
    }
    return head;
}

//方法三：哨兵位节点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
#include <stdlib.h>
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    //1、避免空链表
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    //2、非空链表
    struct ListNode* head = NULL;//指向头节点的指针，方便返回这个整合后的链表
    struct ListNode* tail = NULL;//指向尾节点的指针

    //3、设置哨兵节点
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

/*    if(list1->val < list2->val)//不管如何先有一个头结点
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }
*/
    while(list1 != NULL && list2 != NULL)//只要list1和list2没有到结尾就一直走下去
    {
        if(list1->val < list2->val)
        {
            /*if(tail == NULL)
            {
                head = tail = list1;
            }
            else
            {*/
                tail->next = list1;
                /*tail = tail->next;//将尾指针挪后
            }*/
            list1 = list1->next;
        }
        else
        {
            /*if(tail == NULL)
            {
                head = tail = list2;
            }
            else
            {*/
                tail->next = list2;
                /*tail = tail->next;//将尾指针挪后
            }*/
            list2 = list2->next;
        }

        tail = tail->next;
    }
    //4、如果经过上述步骤还有链表有剩余元素，就直接接到后面，不必处理（本来就有序）
    if(list1)
    {
        tail->next = list1;
    }
    if(list2)
    {
        tail->next = list2;
    }
    //return head;注意这里不是真正的头，而是哨兵节点，因此不能直接返回
    struct ListNode* first = head->next;
    free(head);
    return first;
}

//判断环形链表：https://leetcode.cn/problems/linked-list-cycle/description/
//快慢指针法
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head)
{
    struct ListNode*slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

// 问题1：请证明slow一定能追上
// 一定能追上，设当slow进入某个开始循环的点时，fast到slow的距离为N，两个指针按照自己的步长前进，得到flast到slow的距离为N-1（N+1-2）、N-2（N+1-2+1-2）、…一直到0时，则两指针相遇。即每次距离缩短1

// 问题2：slow走1次，fast走3次可以么？4次呢？…
// 都不一定能追上，有可能错过
// ①假设fast走奇数次，若开始距离为奇数则追不上；若开始距离为偶数则追得上
// ②假设fast走偶数次，若更加复杂，也是有可能追不上的

//求环形链表的入口点：https://leetcode.cn/problems/linked-list-cycle-ii/
//如果使用快慢指针相遇，标记相遇点为meet，如果此时又有一个指针指向头结点，则两个指针一起向前迈进一步，则相遇时就是指向环入口的节点
//假设环的长度是C，slow走过L，当slow和fast在环内相遇点距离环入口有X
//则根据fast的长度是slow的两倍，得到式子：L+n*C+X==2*(L+X)
//得到式子“L==n*C-X” 
//故若又设一个指向头节点的指针，和meet一起向前走一步
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode*slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            //开始求入口点
            struct ListNode* meet = slow;
            while(head != meet)
            {
                head = head->next;
                meet = meet->next; 
            }
            return meet;
        }
    }  
    return NULL;  
}