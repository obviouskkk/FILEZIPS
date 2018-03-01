/* ***********************************************************************

  > File Name: tesc.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 01 Mar 2018 04:18:57 PM CST

 ********************************************************************** */

#include <stdio.h>

//基于算法导论上面的习题4.1-5来实现的算法
int main()
{
    int A[9] = { 0, -2 ,1 ,-3, 4, -1, 2 ,1 ,-5 };
    int array_length = sizeof(A) / sizeof(A[0]);//数组大小
    int maxSum = A[0];//记录最大子数组的和
    int low=0;//记录最大子数组的底
    int high=0;//记录最大子数组的高
    for (int i = 0; i < array_length-1; i++)
    {
        int sum = 0;
        //寻找以A[i+1]为终点的最大子数组
        for (int j = i+1; j>=0; j--)
        {
            sum += A[j];
            if (sum>maxSum)
            {
                maxSum = sum;
                low = j;
                high = i + 1;
            }
        }
    }
    printf("%d  %d  %d", low, high,maxSum);//将结果打印出来
    getchar();
    return 0;
}
