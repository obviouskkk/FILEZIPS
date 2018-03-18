/* ***********************************************************************

  > File Name: endSumSubArr.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 01 Mar 2018 03:02:11 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>

/* 连续子数组，最大和
 * 基本思想:负数越加越小，还不如单独数
 * 保存一个max值，防止数组全是负的
 * 保存一个返回值 sum；一个临时和 sum_temp
 * 如果sum_temp < 0 ;回滚到0
 * 如果sum_temp > sum,保存到sum
 * 返回值:
 * 判断 sum，小于0说明全是负的，返回最大值max;其他情况返回sum
 */
int MaxSumSubArr(const std::vector<int> & arr)
{
    int sum = 0, max = arr[0];
    int sum_temp = 0;
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i] > max)
            max = arr[i];
        sum_temp += arr[i];
        if (sum_temp > sum)
            sum = sum_temp;
        else if (sum_temp < 0)
            sum_temp = 0;
    }
    if (sum == 0)
        return max;
    else 
        return sum;
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> arr;
    for (int i = 0; i < size; ++i){
        int a ;
        std::cin >>  a;
        arr.push_back(a);
    }
    printf("%d", MaxSumSubArr(arr));
}
