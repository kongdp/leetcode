/*
 * ***************************************************************************
 * PROJECT     : leetcode
 * FILE NAME   : 21_mergeTwoLists.c
 * CREATE DATE : 2018-11-24
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *h, *t;
   
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    /* 头结点存储 */
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
    
    /* 读取公共部分 */
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
    
    /* 读取后续部分 */
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