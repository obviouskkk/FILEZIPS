/* ***********************************************************************

  > File Name: test.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 01 Mar 2018 04:25:58 PM CST

 ********************************************************************** */

#include <iostream>
#include <stdio.h>

int main()
{
	int A[8] = { -6, -10, -5, -6, -7, -1, -1 };
	int array_length = sizeof(A) / sizeof(A[0]);//数组大小
	int sum = 0;//记录子数组的和
	int thisSum = 0;
	for (int i = 0; i < array_length; i++)
	{
		thisSum += A[i];
		if (thisSum > sum)
		{
			sum = thisSum;
		}
		else if (thisSum < 0)
		{
			thisSum = 0;
		}
	}
    printf("%d", sum);
    return 0;
}

