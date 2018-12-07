/*
 * ***************************************************************************
 * PROJECT     : leetcode
 * FILE NAME   : 24_swapPairs.c
 * CREATE DATE : 2018-11-26
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

// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

// 示例:

// 给定 1->2->3->4, 你应该返回 2->1->4->3.
// 说明:

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
Func Name   : swapPairs
Description : 将元素两两交换
Input(s)    : head 输入链表头指针
Output(s)   : 
Return      : 变换后的链表
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode* swapPairs(struct ListNode* head) 
{
    /* 上一级   | --- 待交换的节点 ---|*/
    /* p------->p1------->p2-------> */
    struct ListNode *h, *p, *p1, *p2;
    if(head == NULL || head->next == NULL) return head;
    /*前两个节点特殊处理*/
    h = head->next;
    head->next = h->next;
    h->next = head;

    p   = head; /* head已经是第二个节点 */
   
    while(p != NULL)
    {
        p1  = p->next;
        if(p1 == NULL) break;

        p2 = p1->next;
        if(p2 == NULL) break;

        /* 实现交换 */
        p->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        
        p = p1;
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

    p = swapPairs(&g_head[0]);

    PrintList(p);

    while(1);
    return 0;
}
