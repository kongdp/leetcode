/*
 * ***************************************************************************
 * PROJECT     : leetcode
 * FILE NAME   : 17_letterCombinations.c
 * CREATE DATE : 2018-11-22
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
void ListApend(struct ListNode *head, int data)
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
    struct ListNode *p = head->next;

    while(p)
    {
        printf("%d->", p->val);
        p = p->next;        
    }
    printf("\r\n");
}

/*******************************************************************************
Func Name   : removeNthFromEnd
Description : 移除倒数第n个节点
Input(s)    : head 头指针
              n    倒数n个
Output(s)   : 
Return      : 头指针
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    int count = 0;
    struct ListNode *h, *t;

    if(head == NULL || n == 0) return head;

    h = head;
    t = head;

    while(t->next != NULL)
    {
        if(count < n)
        {
            count++;
            t = t->next;
        }
        else
        {
            h = h->next;
            t = t->next;
        }
    }

    /* 循环完毕,进行删除 */
    if(h->next == t)
    {
        free(h->next);
        h->next = NULL;
    }
    else
    {
        free(h->next);
        h->next = t;
    }

    return head;
}

struct ListNode g_head;
int main()
{
    int i;
    
    g_head.next = NULL;
    g_head.val = 0;

    for(i=1; i<3; i++)
    {
        ListApend(&g_head, i);
    }
    
    PrintList(&g_head);

    removeNthFromEnd(&g_head, 2);

    PrintList(&g_head);

    while(1);
    return 0;
}
