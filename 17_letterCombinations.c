//����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
//
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
//
//
//
//ʾ��:
//
//���룺"23"
//�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//˵��:
//��������Ĵ��ǰ��ֵ������еģ��������������ѡ��������˳��

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ���尴��  */
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

/* ���尴����Ӧ����ĸ */
const char tel[NUMS][4] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

/* ����ÿ�����ִ�����ַ��� */
const int numStrs[NUMS] = { 3, 3, 3, 3, 3, 4, 3, 4 };

/*******************************************************************************
Func Name   : letterCombinations
Description : �������������,������Ӧ���ֶ�Ӧ�İ����ַ���
Input(s)    : digits      �����ַ���
Output(s)   : returnSize  �������
Return      : ָ�򷵻��ַ������ָ��
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

    /* ���������ַ����ĳ��� */
    digitLen = strlen(digits);

    if(digitLen == 0) return NULL;

    /* ��������Ϸ��Լ�� */
    for(i = 0; i<digitLen; i++)
    {
        if(digits[i] >'9' || digits[i] < '2') return NULL;
    }

    /* ÿ�����ִ�����ַ������Ⱥͺ���������ȡ��ÿ�����ִ����ַ����ĵ�ǰλ�� */
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

        /* ���һ��λ��+1 */
        stringPos[digitLen - 1]++;

        /* ���ý�λ�ķ�ʽ,��ǰ�����ѯ��λ */
        for(k = (digitLen - 1); k >= 0; k--)
        {
            if(stringPos[k] >= stringLen[k])
            {
                /* ��ǰλ����Ϊ0 */
                stringPos[k] = 0;
                /* ǰλ��1 */
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

