/* ***********************************************************************

  > File Name: heapSort.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 12 Mar 2018 10:05:10 AM CST

 ********************************************************************** */

#include <cstdio>
#include <vector>
#include <iterator>

inline int left(int num) 
{
    return (num << 1) + 1;
}

inline int right(int num) 
{
    return (num << 1) + 2;
}

void change(std::vector<int> & arr, int begin, int length)
{
    while(left(begin) <= length) 
    {
        if (right(begin) <= length) {
            int left_child  = arr[left(begin)];
            int right_child = arr[right(begin)];
            int largest;
            if (left_child > right_child) 
                largest = left(begin);
            else 
                largest = right(begin);
            if (arr[begin] < arr[largest]) {
                std::swap(arr[begin] , arr[largest]);
                begin = largest;
            }
            else 
                break;
        } else {
            if (arr[begin] < arr[left(begin)]) {
                std::swap(arr[begin] , arr[left(begin)]);
                begin = left(begin);
            } else
                break;
        }
    }
}

void heap_sort(std::vector<int> & arr)
{
    int length = arr.size() -1;
    for (int i = length / 2; i >= 0; --i) {
        change(arr, i, length);
    }
    for (int i = length; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        change(arr, 0, i - 1);
        for (auto var : arr)
            printf("%d ", var);
        printf("\n");
    }
}



int main()
{
    int vec[]={12, 9, 5, 8, 4, 7 ,3, 2, 6, 2, 31, 23 };
    std::vector<int> arr(std::begin(vec), std::end(vec));
    heap_sort(arr);
    for (auto var : arr)
        printf("%d ", var);
    printf("\n");
    return 0;
}
