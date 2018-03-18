/* ***********************************************************************

  > File Name: InsertSort.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Mar 2018 02:20:20 PM CST

 ********************************************************************** */

#include <cstdio>
#include <vector>
#include <iterator>

/*
 * 插入排序
 * 每次发现后面的数字比前面的小，就他插入到合适位置
 * 插入一个数，其他数字得移动，
*/
void InsertSort(std::vector<int>& arr, int len) {
    for (int i = 1; i < len; ++i) {
        if (arr[i] < arr[i-1]) {
            // 移动
            int tmp = arr[i];
            int j = 0;
            for (j = i; j > 0; --j) {
                if (tmp < arr[j-1]) {
                    arr[j] = arr[j-1];
                } else {
                    break;
                }
            }
            // 插入
            arr[j] = tmp;
        }
    }
}

int main()
{
    int vec[]={9, 5, 8, 4, 7 ,3, 2, 6};
    std::vector<int> arr(std::begin(vec), std::end(vec));
    for (auto var : arr)
        printf("%d ", var);
    printf("\n");
    InsertSort(arr, arr.size());
    for (auto var : arr)
        printf("%d ", var);
    printf("\n");
    return 0;
}
