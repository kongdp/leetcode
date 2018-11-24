/*
 * ***************************************************************************
 * PROJECT     : leetcode
 * FILE NAME   : 20_isValid.c
 * CREATE DATE : 2018-11-24
 * AUTHOR      : kevin
 * VERSION     : V1.0d
 * DESCRIPISION: 采用压栈的方式,判断括号的匹配
 * ---------------------------------------------------------------------------
 * Copyright SHANDONG CONTACT COMMUNICATION TECHNOLOGY L.T.D
 * ---------------------------------------------------------------------------
 * HISTORY:
 * Date        By     Comments
 * ----------  -----  --------------------------------------------------------
 * ***************************************************************************
 */

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true  1
#define false 0


struct ListNode {
    char    val;
    struct ListNode *next;
 };

/*******************************************************************************
Func Name   : ListPush
Description : 添加到队列尾
Input(s)    : head 队尾指针
              data 要插入的数据
Output(s)   : 
Return      : 

Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
void ListPush(struct ListNode **head, char data)
{
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));

    if(p)
    {
        p->val  = data;
        p->next = *head;

        *head = p;
    }   
}

/*******************************************************************************
Func Name   : ListPop
Description : 出栈操作
Input(s)    : head 队尾指针
Output(s)   : 
Return      : 

Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-11              kongdepeng    Created
*******************************************************************************/
struct ListNode *ListPop(struct ListNode **head)
{
    struct ListNode *p = *head;

    if(p) *head = p->next;

    return p;
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
        printf("%c->", p->val);
        p = p->next;        
    }
    printf("\r\n");
}

bool isMatch(char a, char b)
{
    if(a == '(')
    {
        return b==')'?true:false;
    }
    else if(a == '[')
    {
        return b==']'?true:false;
    }
    else if(a == '{')
    {
        return b=='}'?true:false;
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
bool isValid(char* s) 
{
    int len, i;
    struct ListNode *g_head = NULL, *p;

    if(s == NULL || (len = strlen(s)) == 0) return true;

    if(len%2 == 1) return false;

    for(i=0;  i<len; i++)
    {
        if(*s == '(' ||*s == '{' ||*s == '[') 
        {
            ListPush(&g_head, *s);
        } 
        else
        {
            p = ListPop(&g_head);

            if(p == NULL)      return false;
            if(isMatch(p->val, *s) == 0) rseturn false;
        } 
        s++;     
    }

    if(g_head) return false;

    return true;
}

struct ListNode *g_head = NULL;
int main()
{
    if(isValid("(){[}]") == true)
    {
        printf("true;\r\n");
    }
    else
    {
        printf("false\r\n");
    }

    while(1);
    return 0;
}
