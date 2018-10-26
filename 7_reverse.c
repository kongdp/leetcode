//给定一个 32 位有符号整数，将整数中的数字进行反转。
//
//示例 1:
//
//输入: 123
//输出: 321
// 示例 2:
//
//输入: -123
//输出: -321
//示例 3:
//
//输入: 120
//输出: 21
//注意:
//
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int reverse(int x) {
    int tmp;
    int t = 0;
    
    while(x!=0)
    {
        tmp=x%10;

		x=x/10;

		if((t>INT_MAX/10) ||(t==INT_MAX/10 && tmp>7)) return 0;

        if((t<INT_MIN/10) ||(t==INT_MIN/10 && tmp<-8)) return 0;

        t=t*10+tmp;
    }
    
	return t;
}

int main_7()
{
	int d = -147483648;

	d = reverse(d);

	printf("%d \r\n", d);

	printf("%d \r\n", sizeof(float));

	while(1);
	return 0;
}