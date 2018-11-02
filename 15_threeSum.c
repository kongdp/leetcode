/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
    [-1, -1, 2]
    ]
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int noRepect(int **a, int size, int *num)
{
    int i, j, t;

    /* 给三个数字从小到大排序 */
    for(i=0; i<3; i++)
    {
        for(j=i+1; j<3; j++)
        {
            if(num[i]>num[j])
            {
                t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
        }
    }

    //printf("%d, %d, %d\r\n", num[0], num[1], num[2]);

    if(size == 0) return 1;

    for(i=0; i<size; i++)
    {
        if((num[0] == (a[i])[0]) &&
            (num[1] == (a[i])[1]) &&
            (num[2] == (a[i])[2]))
        {
            break;
        }
    }

    if(i == size) return 1;
    else          return 0;
}

/*******************************************************************************
Func Name   : threeSum
Description : 三数字之和，如果是0，则返回
Input(s)    : nums 整数数组
              numsSize 整数个数
Output(s)   : returnSize 三数字数组个数
Return      : 整数数组的指针的指针
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-29           kongdepeng    Created
*******************************************************************************/
int **threeSum(int* nums, int numsSize, int* returnSize)
{
    int i, j, k;
    *returnSize = 0;
    int **a = NULL; 
    int temp[3];
    if(nums == NULL) return NULL;

    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            for(k=j+1; k<numsSize; k++)
            {
                /* 满足和为0的条件 */
                if((nums[i]+nums[j]+nums[k]) == 0)
                {
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];

                    /* 去重并从小到大排序 */
                    if(noRepect(a, *returnSize, temp))
                    {
                        a = (int **)realloc((int **)a, sizeof(int *)*(*returnSize+1));
                        
                        if(a)
                        {
                            a[*returnSize] = (int*)malloc(sizeof(int)*3);
                            if(a[*returnSize])
                            {
                                (a[*returnSize])[0] = temp[0];
                                (a[*returnSize])[1] = temp[1];
                                (a[*returnSize])[2] = temp[2];
                                (*returnSize) += 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return a;
}


int main(void)
{
    int count, i;
    int nums[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};

    int **p;

    p = threeSum(nums, sizeof(nums)/sizeof(int), &count);

    if(count>0)
    {
        for(i=0; i<count; i++)
        {
            printf("%d, %d, %d\r\n", (p[i])[0], (p[i])[1], (p[i])[2]);
        }
    }

    return 0;
}
