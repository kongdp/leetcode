#include <stdlib.h>
#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *node;
	int flag = 0;

	if((l1==NULL) || (l2==NULL)) return NULL;
	
	node = (struct ListNode*)malloc(sizeof(struct ListNode));

	if(node != NULL)
	{
		node->val = 0;
		node->next = NULL;
	}
	else
	{
		return NULL;
	}

	head = node;

	while(l1!=NULL || l2!=NULL || flag == 1)
	{
		if(l1!=NULL)
		{
			node->val+=l1->val;
			l1=l1->next;
		}

		if(l2!=NULL)
		{
			node->val+=l2->val;
			l2=l2->next;
		}
		node->val += flag;

		if(node->val >= 10)
		{
			flag = 1;
			node->val-=10;
		}
		else
		{
			flag = 0;
		}
		
		if(l1!=NULL || l2!=NULL || flag==1)
		{
			node->next = (struct ListNode*)malloc(sizeof(struct ListNode));

			if(node->next != NULL)
			{
				node = node->next;
				node->val = 0;
				node->next = NULL;
			}
			else
			{
				return NULL;
			}
		}
	}

	return head;
}

void PrintfList(struct ListNode *L)
{
	while(L)
	{
		printf("%d->", L->val);

		L=L->next;
	}

	printf("\r\n");
}


int main_2()
{

	return 0;
}