//����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
//
//���磬�������� nums = [-1��2��1��-4], �� target = 1.
//
//�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ABS(x) ((x)>0?(x):(-(x)))

/*******************************************************************************
Func Name   : QuickSort
Description : c����ʵ�ֿ�������
Input(s)    : s ��������
              l ���(0)
              r �Ҳ�(length)
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
            while(i<j && s[j] >= x)//���ҵ����ҵ���һ��С��x����  
                j--;
            if(i<j)
                s[i++] = s[j];

            while(i<j && s[i] <= x)//���������ҵ���һ������x����  
                i++;
            if(i<j)
                s[j--] = s[i];

        }

        s[i] = x;//i = j��ʱ�򣬽�x�����м�λ��  
        QuickSort(s, l, i - 1);//�ݹ���� 
        QuickSort(s, i + 1, r);
    }
}


/*******************************************************************************
Func Name   : threeSumClosest
Description : ������֮����ӽ�target������������Ϊ˫ָ�뷨�����Ӷ�Ϊn2
Input(s)    : nums     ��������
              numsSize ��������
              target   Ŀ������
Output(s)   : 
Return      : ����֮��
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

    /* �Ƚ�������,����������� */
    QuickSort(nums, 0, numsSize - 1);

    sum = nums[0] + nums[1] + nums[2];
    
    diff = sum - target;

    if(nums[0] == nums[numsSize - 1]) return sum;

    for(i = 0; i<numsSize; i++)
    {
        /* ��ʼ��ͷβָ�� */
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
            else if((nums[p1] + nums[p2]) == (target - nums[i]))
            {
                return target;
            }
        }
        /* ȥ�ش��� */
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
