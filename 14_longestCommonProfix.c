/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*******************************************************************************
Func Name   : longestCommonPrefix
Description : 查找最长公共前缀
Input(s)    : strs 字符串数组
              strsSize 字符串数组个数
Output(s)   : 
Return      : 公共字符串(注意：没有公共前缀时返回空字符串，而不是NULL)
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-29           kongdepeng    Created
*******************************************************************************/
char* longestCommonPrefix(char** strs, int strsSize) 
{
    char *p, c;
    int i, j, len;

    len = strlen(*strs);

    p = (char*)calloc(strlen(*strs)+1, sizeof(char));

    if(p == NULL) return NULL;
    
    for(i=0; i<len; i++)
    {
        /* 取第一个字符串的第i个字符 */
        c = (*strs)[i];

        for(j=1; j<strsSize; j++)
        {
            if((c != (*(strs+j))[i]) 
            || (c == '\0'))
            {
                break;
            }
        }

        /* 判断j的大小确定当前字符是否成立 */
        if(j == strsSize)
        {
            p[i] = c;
        }
        else
        {
            break;
        }
    }

    return p; 
}


int main(void)
{
    char *ptr[3];
    char str1[3][10] = {"flower", "flow", "flight"};

    ptr[0] = str1[0];
    ptr[1] = str1[1];
    ptr[2] = str1[2];

    char *p = longestCommonPrefix(ptr, 3);

    if(p)
    {
        printf("p = %s\r\n", p);
        free(p);
    }

    return 0;
}
