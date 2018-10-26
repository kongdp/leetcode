//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//
//示例 1:
//
//输入: 121
//输出: true
//示例 2:
//
//输入: -121
//输出: false
//解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
//示例 3:
//
//输入: 10
//输出: false
//解释: 从右向左读, 为 01 。因此它不是一个回文数。
//进阶:
//
//你能不将整数转为字符串来解决这个问题吗？

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define false 0
#define true 1

/*******************************************************************************
Func Name   : isPalindrome
Description : 判断整数是否为回文
Input(s)    : x 整数
Output(s)   : 
Return      : true 是回文
              false 不是回文
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