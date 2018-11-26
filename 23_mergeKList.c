/*
 * ***************************************************************************
 * PROJECT     : leetcode
 * FILE NAME   : 22_mergeKList.c
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

// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

// 示例:

// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

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
Func Name   : mergeTwoLists
Description : 合并两个链表
Input(s)    : l1 链表1
              l2 链表2
Output(s)   : 
Return      : 合并后的链表
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *h, *t;
   
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    if(l1->val <= l2->val)
    {
        t = h = l1;
        l1 = l1->next;
    }
    else
    {
        t = h = l2;
        l2 = l2->next;
    }
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            t->next = l1;
            l1 = l1->next;
            t = t->next;
        }
        else
        {
            t->next = l2;
            l2 = l2->next;
            t = t->next;
        }
    }
    
    if(l1 != NULL)
    {
        t->next = l1;
    }

    if(l2 != NULL)
    {
        t->next = l2;
    }
    
    return h;
    
}

/*******************************************************************************
Func Name   : mergeKLists
Description : 合并多个链表
Input(s)    : lists     输入的多个链表
              listsSize 链表个数
Output(s)   : 
Return      : 合并后的链表
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
    struct ListNode *p = NULL;
    int i;
    
    for(i=0; i<listsSize; i++)
    {
        p = mergeTwoLists(p, lists[i]);
    }
    
    return p;
}


struct ListNode g_head[3];
int main()
{
    int i;
    struct ListNode *p;

    g_head[0].next = NULL;
    g_head[0].val = 1;
    ListAppend(&g_head[0], 4);
    ListAppend(&g_head[0], 5);
    PrintList(&g_head[0]);


    g_head[1].next = NULL;
    g_head[1].val = 1;
    ListAppend(&g_head[1], 3);
    ListAppend(&g_head[1], 4);
    PrintList(&g_head[1]);

    g_head[2].next = NULL;
    g_head[2].val = 2;
    ListAppend(&g_head[2], 6);
    PrintList(&g_head[2]);

    p = mergeTwoLists(&g_head[0],&g_head[1]);

    PrintList(p);

    while(1);
    return 0;
}
