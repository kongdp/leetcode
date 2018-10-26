//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ1000��
//
//ʾ�� 1��
//
//����: "babad"
//���: "bab"
//ע��: "aba"Ҳ��һ����Ч�𰸡�
//ʾ�� 2��
//
//����: "cbbd"
//���: "bb"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int val;
    struct MyLinkedList *next;
    
} MyLinkedList;

#define MAXLEN 1000

//-----  ��ֽ����(�Լ����뷨��Ч�ʱȽϵ�)
char* longestPalindrome(char* s) 
{
    int count=0, max=0, i=0, j=0, len=0;

	char *ptr=NULL, *ret;

	if(s == NULL) return NULL; 

	len = strlen(s);

	while(i<len || j<len)
	{
		count = 0;
		while((i-count)>=0 && (j+count)<len)
		{
			if(s[i-count] == s[j+count])
			{
				if((j-i+2*count+1)>max)
				{
					max = j-i+2*count+1;

					ptr = &s[i-count];
				}
				count++;
			}
			else
			{
				break;
			}
		}

		if(i==j)
		{
			j++;
		}
		else
		{
			i++;
		}

	}

	ret = (char *)calloc(max+1, sizeof(char));

	if(ret)
	{
		memcpy(ret, ptr, max);

		return ret;
	}

	return NULL;
}

int main_5()
{
	char str[]= "aabc";
	char * ptr;

	ptr = longestPalindrome(str);

	printf("%s \r\n", ptr);

	while(1);
	return 0;
}