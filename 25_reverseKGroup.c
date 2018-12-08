/*
 * ***************************************************************************
 * PROJECT     : leetcode
 * FILE NAME   : 25_reverseKGroup.c
 * CREATE DATE : 2018-12-07
 * AUTHOR      : kevin
 * VERSION     : V1.0
 * DESCRIPISION: 
 * ---------------------------------------------------------------------------
 * Copyright SHANDONG CONTACT COMMUNICATION TECHNOLOGY L.T.D
 * ---------------------------------------------------------------------------
 * HISTORY:
 * Date        By     Comments
 * ----------  -----  --------------------------------------------------------
 * ***************************************************************************
 */

// 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

// 示例 :

// 给定这个链表：1->2->3->4->5

// 当 k = 2 时，应当返回: 2->1->4->3->5

// 当 k = 3 时，应当返回: 3->2->1->4->5

// 说明 :

// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
 };

/*******************************************************************************
Func Name   : ListApend
Description : 添加到末尾
Input(s)    : head 头指针
              data 要添加的数据
Output(s)   : 
Return      : 

Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
void ListAppend(struct ListNode *head, int data)
{
    while(head->next != NULL)
    {
        head = head->next;        
    }

    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));

    if(head->next)
    {
        head->next->val = data;
        head->next->next = NULL;
    }
}

/*******************************************************************************
Func Name   : PrintList
Description : 打印链表数据
Input(s)    : head 头指针
Output(s)   : 
Return      : 
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
void PrintList(struct ListNode *head)
{
    struct ListNode *p = head;

    while(p)
    {
        printf("%d->", p->val);
        p = p->next;        
    }
    printf("\r\n");
}

/*******************************************************************************
Func Name   : reverseKNode
Description : 链表反转N个节点
Input(s)    : head 输入链表头指针
              k    反转元素个数
Output(s)   : 
Return      : 变换后的链表
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode* reverseKNode(struct ListNode* head, int k)
{
    struct ListNode *h, *p, *t;
    int i = 2;
    if(head == NULL || head->next == NULL || k <= 1) return head;

    h = head;
    p = h->next;

    while(p != NULL && i <= k)
    {
        i++;

        t = p->next;
        p->next = h;
        h = p;
        p = t;
    }

    head->next = t;

    return h;
}

/*******************************************************************************
Func Name   : reverseKGroup
Description : 链表反转
Input(s)    : head 输入链表头指针
              k    反转元素个数
Output(s)   : 
Return      : 变换后的链表
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    int i;
    /*  lastEnd       curHead   k=3    p2 | nextHead */
    /*                 0         1      2 |   3      */
    struct ListNode *h, *t, *curHead, *lastEnd, *nextHead;
    if(head == NULL || head->next == NULL || k <= 1) return head;

    curHead = nextHead = head;
    lastEnd = NULL;
    
    while(nextHead != NULL)
    {
        nextHead = nextHead->next;
        i++;

        if(i%k == 0)
        {
            /* 记录反转后的新段头 */
            t = reverseKNode(curHead, k);

            /* 上一级的末尾指向此段头 */
            if(lastEnd != NULL)
            {
                lastEnd->next = t;                
            }
            else /* 如果为空,则需要记录头结点 */
            {
                h = t;
            }

            /* 记录反转段上一级的尾 */
            lastEnd = curHead;
            /* 记录等待反转段的头 */
            curHead = nextHead;
        }
    }
    
    return h;
}

struct ListNode g_head[3];
int main()
{
    int i;
    struct ListNode *p;

    g_head[0].next = NULL;
    g_head[0].val = 1;
    ListAppend(&g_head[0], 2);
    ListAppend(&g_head[0], 3);
    ListAppend(&g_head[0], 4);
    ListAppend(&g_head[0], 5);
    PrintList(&g_head[0]);

    p = reverseKGroup(&g_head[0], 3);

    PrintList(p);

    while(1);
    return 0;
}
