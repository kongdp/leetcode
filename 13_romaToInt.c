/*
 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

 字符          数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

 I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

 示例 1:

 输入: "III"
 输出: 3
 示例 2:

 输入: "IV"
 输出: 4
 示例 3:

 输入: "IX"
 输出: 9
 示例 4:

 输入: "LVIII"
 输出: 58
 解释: L = 50, V= 5, III = 3.
 示例 5:

 输入: "MCMXCIV"
 输出: 1994
 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 */

#include <stdlib.h>
#include <stdio.h>

/*******************************************************************************
Func Name   : singleRomanToInt
Description : 单个罗马数字转整型数
Input(s)    : c 罗马数字
Output(s)   : 
Return      : 罗马数字代表的整型数
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-27           kongdepeng    Created
*******************************************************************************/
int singleRomanToInt(char c)
{
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    if(c == 'M') return 1000;
    return 0;
}

/*******************************************************************************
Func Name   : romanToInt
Description : 罗马数字字符串转整型数
Input(s)    : str 输入字符串
Output(s)   : 
Return      : 整型数
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-24           kongdepeng    Created
*******************************************************************************/
int romanToInt(char *str)
{
    int t = 0, p1 = 0, t1 = 0;

    if(str == NULL) return 0;
    
    while(*str != '\0')
    {
        p1 = singleRomanToInt(*str++);

        t1 = singleRomanToInt(*str);

        if(t1 > p1)
        {
            t += (t1-p1);
            str++;
        }
        else
        {
            t += p1;
        }
    }

    return t;
}


int main(void)
{
    char str1[] = "IV";
    char str2[] = "MMMDXXXVI";
    int t1, t2;

    t1 = romanToInt(str1);
    t2 = romanToInt(str2);

    printf("t1 = %d, t2 = %d \r\n", t1, t2);

    return 0;
}
