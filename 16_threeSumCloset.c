//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//
//例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
//
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ABS(x) ((x)>0?(x):(-(x)))

/*******************************************************************************
Func Name   : QuickSort
Description : c语言实现快速排序
Input(s)    : s 整数数组
              l 左侧(0)
              r 右侧(length)
Output(s)   : 
Return      : 
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-29           kongdepeng    Created
*******************************************************************************/
static void QuickSort(int s[], int l, int r)
{
    if(l < r)
    {
        int i = l, j = r, x = s[l];
        while(i<j)
        {
            while(i<j && s[j] >= x)//从右到左找到第一个小于x的数  
                j--;
            if(i<j)
                s[i++] = s[j];

            while(i<j && s[i] <= x)//从左往右找到第一个大于x的数  
                i++;
            if(i<j)
                s[j--] = s[i];

        }

        s[i] = x;//i = j的时候，将x填入中间位置  
        QuickSort(s, l, i - 1);//递归调用 
        QuickSort(s, i + 1, r);
    }
}


/*******************************************************************************
Func Name   : threeSumClosest
Description : 三数字之和最接近target的数，本方法为双指针法，复杂度为n2
Input(s)    : nums     整数数组
              numsSize 整数个数
              target   目标整数
Output(s)   : 
Return      : 三数之和
Others      :
------------------------------------------------------------------------------
History
Date(yyyy-mm-dd)     Author        Modification
2018-10-29           kongdepeng    Created
*******************************************************************************/
int threeSumClosest(int* nums, int numsSize, int target)
{
    int i, p1, p2;
    int sum = 0, diff = 0;
    
    if(nums == NULL || numsSize < 3) return sum;
    if(numsSize == 3) return (nums[0] + nums[1] + nums[2]);

    /* 先进行排序,方便后续处理 */
    QuickSort(nums, 0, numsSize - 1);

    sum = nums[0] + nums[1] + nums[2];
    
    diff = sum - target;

    if(nums[0] == nums[numsSize - 1]) return sum;

    for(i = 0; i<numsSize; i++)
    {
        /* 初始化头尾指针 */
        p1 = i+1; 
        p2 = numsSize - 1;

        while(p1 < p2)
        {
            if((nums[p1] + nums[p2]) < (target - nums[i]))
            {
                if(ABS(nums[i] + nums[p1] + nums[p2] - target) < ABS(diff))
                {
                    sum = nums[i] + nums[p1] + nums[p2];

                    diff = nums[i] + nums[p1] + nums[p2] - target;
                }
                p1++;
            }
            else if((nums[p1] + nums[p2]) > (target - nums[i]))
            {
                if(ABS(nums[i] + nums[p1] + nums[p2] - target) < ABS(diff))
                {
                    sum = nums[i] + nums[p1] + nums[p2];

                    diff = nums[i] + nums[p1] + nums[p2] - target;
                }
                p2--;
            }
            else if((nums[p1] + nums[p2]) == (0 - nums[i]))
            {
                return 0;
            }
        }
        /* 去重处理 */
        while(nums[i] == nums[i + 1] && i<numsSize){ i++; }
    }

    return sum;
}


int nums2[] = { -7, -4, -6, 6, 4, -6, -9, -10, -7, 5, 3, -1, -5, 8, -1, -2, -8, -1, 5, -3, -5, 4, 2, -5, -4, 4, 7 };

int nums3[] = {-1, 0, 1, 2, -1, -4};

int nums4[] = { 1, 1, -1, -1, 3};

int main(void)
{
    int count = 0, i;

    int p;

    p = threeSumClosest(nums4, sizeof(nums4) / sizeof(int), 1);

    printf("p = %d\r\n", p);


    while(1);

    return 0;
}
