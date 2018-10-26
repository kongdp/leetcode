//����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�
//
//ʾ�� 1:
//
//����: "abcabcbb"
//���: 3 
//����: ���ظ��ַ�����Ӵ��� "abc"���䳤��Ϊ 3��
//ʾ�� 2:
//
//����: "bbbbb"
//���: 1
//����: ���ظ��ַ�����Ӵ��� "b"���䳤��Ϊ 1��
//ʾ�� 3:
//
//����: "pwwkew"
//���: 3
//����: ���ظ��ַ�����Ӵ��� "wke"���䳤��Ϊ 3��
//     ��ע�⣬�𰸱�����һ���Ӵ���"pwke" ��һ�������� �������Ӵ���

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
	int hash[256] = {0}; 
	int max = 0;
	int i = 0, j = 0; 
	int len = strlen(s);

	while (i < len && j <len ) 
	{ 
		if(hash[(int)s[j]] == 0)
		{ 
			hash[(int)s[j]] = 1; 
			j++; 
			max = (j - i) > max ? (j - i) : max; 
		} 
		else 
		{ 
			hash[(int)s[i]] = 0; 
			i++; 
		} 
	} 
	return max;
}


int main_3()
{
	char str[]= "abcbaef";
	int len;

	len = lengthOfLongestSubstring(str);

	printf("%d \r\n", len);

	while(1);
	return 0;
}