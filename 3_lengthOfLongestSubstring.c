//给定一个字符串，找出不含有重复字符的最长子串的长度。
//
//示例 1:
//
//输入: "abcabcbb"
//输出: 3 
//解释: 无重复字符的最长子串是 "abc"，其长度为 3。
//示例 2:
//
//输入: "bbbbb"
//输出: 1
//解释: 无重复字符的最长子串是 "b"，其长度为 1。
//示例 3:
//
//输入: "pwwkew"
//输出: 3
//解释: 无重复字符的最长子串是 "wke"，其长度为 3。
//     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。

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