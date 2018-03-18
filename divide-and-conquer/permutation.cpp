/* ***********************************************************************

  > File Name: permutation.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 02 Mar 2018 10:26:47 AM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>


void permutation(std::string &arr, int begin, int end)
{
    if (begin >= end) 
        return;
    if (begin == end - 1) {
        printf("%s\n", arr.c_str());
    }
    for (int i = begin; i < end; i++) {
        std::swap(arr[begin], arr[i]);
        permutation(arr, begin + 1, end);
        std::swap(arr[begin], arr[i]);
    }
    return;
}

int main()
{
    std::string str = "ab";
    permutation(str, 0, str.size());
    return 0;
}

