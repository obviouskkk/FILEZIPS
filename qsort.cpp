/* ***********************************************************************

  > File Name: qsort.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 17 Feb 2018 09:33:02 PM CST

 ********************************************************************** */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>


int qsort_pos(std::vector<int> & vec, int begin, int end)
{
    int key = vec[begin];
    while (begin < end){
        while (begin < end && vec[end] >= key) 
            --end;
        vec[begin] = vec[end];
        while (begin < end && vec[begin] <= key)
            ++begin;
        vec[end] = vec[begin];
    }
    vec[begin] = key;
    return begin;
}


void  qsort(std::vector<int> & vec, int begin, int end)
{   
    std::for_each(vec.begin(), vec.end(), [](int n){printf("%d  ", n);});
    printf("\n");
    if(begin < end) {
        int key =  qsort_pos(vec, begin, end);
        printf("%d\n", key);
        qsort(vec, begin, key - 1);
        qsort(vec, key + 1, end);
    }
}


int main()
{
    int sort_set[] = {1, 6, 14, 7, 76, 2,18, 42, 44, 10};
    std::vector<int> vec(sort_set, sort_set + sizeof(sort_set) / sizeof(int));
    qsort(vec, 0, vec.size() - 1 );
    return 0;
}

