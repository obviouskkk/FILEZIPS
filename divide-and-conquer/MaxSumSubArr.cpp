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
