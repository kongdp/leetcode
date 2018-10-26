//�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
//
//ʾ�� 1:
//
//����: 121
//���: true
//ʾ�� 2:
//
//����: -121
//���: false
//����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
//ʾ�� 3:
//
//����: 10
//���: false
//����: ���������, Ϊ 01 �����������һ����������
//����:
//
//���ܲ�������תΪ�ַ�����������������

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define false 0
#define true 1

/*******************************************************************************
Func Name   : isPalindrome
Description : �ж������Ƿ�Ϊ����
Input(s)    : x ����
Output(s)   : 
Return      : true �ǻ���
              false ���ǻ���
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-09-12           kongdepeng    Created
*******************************************************************************/

bool isPalindrome(int x) 
{
	long long t = x, y = 0;

	if(x<0) return false;

	while(t != 0)
	{
		y = y*10+t%10;

		t = t/10;
	}

	if(x == y) return true;
	else      return false;
}

int main()
{
	int d = 10;

	d = isPalindrome(d);

	printf("%d \r\n",d);

	while(1);

	return 0;
}