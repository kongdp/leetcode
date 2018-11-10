//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//说明:
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 定义按键  */
enum{
    NUM_2 = 0,
    NUM_3,
    NUM_4,
    NUM_5,
    NUM_6,
    NUM_7,
    NUM_8,
    NUM_9,
    NUMS,
};

/* 定义按键对应的字母 */
const char tel[NUMS][4] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

/* 定义每个数字代表的字符数 */
const int numStrs[NUMS] = { 3, 3, 3, 3, 3, 4, 3, 4 };

/*******************************************************************************
Func Name   : letterCombinations
Description : 根据输入的数字,返回相应数字对应的按键字符串
Input(s)    : digits      数字字符串
Output(s)   : returnSize  组合种数
Return      : 指向返回字符数组的指针
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-29           kongdepeng    Created
*******************************************************************************/
char** letterCombinations(char* digits, int* returnSize)
{
    int i, j, k;
    int digitLen, *stringLen, *stringPos;
    int returnStrNum = 1;
    char **a = NULL;

    if(NULL == digits) return NULL;

    /* 输入数字字符串的长度 */
    digitLen = strlen(digits);

    if(digitLen == 0) return NULL;

    /* 进行数组合法性检查 */
    for(i = 0; i<digitLen; i++)
    {
        if(digits[i] >'9' || digits[i] < '2') return NULL;
    }

    /* 每个数字代表的字符串长度和后续用来读取的每个数字代表字符串的当前位置 */
    stringLen = (int *)malloc(sizeof(int)*digitLen);
    stringPos = (int *)malloc(sizeof(int)*digitLen);

    if(NULL == stringLen || NULL == stringPos) return NULL;

    for(i = 0; i<digitLen; i++)
    {
        stringLen[i] = numStrs[digits[i] - '2'];
        stringPos[i] = 0;
        returnStrNum *= stringLen[i];
    }

    a = (char **)malloc(sizeof(char *)*returnStrNum);

    if(NULL == a) return NULL;

    for(i = 0; i<returnStrNum; i++)
    {
        a[i] = (char *)calloc(digitLen + 1, sizeof(char));

        if(NULL == a[i]) return NULL;

        for(j = 0; j<digitLen; j++)
        {
            (a[i])[j] = tel[digits[j] - '2'][stringPos[j]];
        }

        /* 最后一个位置+1 */
        stringPos[digitLen - 1]++;

        /* 采用进位的方式,往前逐个查询进位 */
        for(k = (digitLen - 1); k >= 0; k--)
        {
            if(stringPos[k] >= stringLen[k])
            {
                /* 当前位置置为0 */
                stringPos[k] = 0;
                /* 前位置1 */
                if(k>=1)
                { 
                    stringPos[k - 1]++;
                }
            }
        }
    }

    *returnSize = returnStrNum;

    return a;

}


int main()
{
    char str[] = "", **a;
    int count, i;

    a = letterCombinations(str, &count);

    for(i = 0; i<count; i++)
    {
        printf("%s\r\n", a[i]);
    }

    printf("just test\r\n");
    while(1);
    return 0;
}

