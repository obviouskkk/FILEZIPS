/* ***********************************************************************

  > File Name: MaxSumSubArr_1.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 01 Mar 2018 10:37:48 PM CST

 ********************************************************************** */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>

int MaxSumSubArrCross(const std::vector<int> & arr, int low, int mid,int high)
{
    int max_left = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i-- ){
        sum += arr[i];
        if(sum > max_left)
            max_left = sum;
    }
    int max_right = INT_MIN; 
    sum = 0;
    for (int i = mid + 1; i <= high; ++ i) {
        sum += arr[i];
        if (sum > max_right)
            max_right = sum;
    }
    int ret = max_left + max_right;
    return ret;
}

int MaxSumSubArr(const std::vector<int> & arr, int low, int high)
{
    if (low == high)
        return arr[low];
    int mid = (low + high) / 2;
    int max_left = MaxSumSubArr(arr, low, mid );
    int max_right = MaxSumSubArr(arr, mid + 1 , high) ;
    int max_cross = MaxSumSubArrCross( arr, low, mid, high);
    return std::max(max_left, std::max(max_right, max_cross));
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
    printf("%d", MaxSumSubArr(arr, 0, (int)arr.size() - 1));
}
