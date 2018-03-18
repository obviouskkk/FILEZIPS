/* ***********************************************************************

  > File Name: topK.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Mar 2018 05:22:57 PM CST

 ********************************************************************** */

/*
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

#include <vector>
#include <cstdio>
#include <iterator>
#include <algorithm>

using std::vector;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> retNull;
        if (k == 0 || (int)input.size() < k) {
            return retNull;
        }
        vector<int> ret(input.begin(), input.begin() + k);
        // 建堆
        for (int i = k/2-1; i >= 0 ; --i) {
            change(ret, i, k - 1);
        }
        // 插入
        for (int i = k; i < (int)input.size(); ++i) {
            if (input[i] < ret[0]) {
                ret[0] = input[i];
                change(ret, 0, k - 1);
            }
        }
        return ret;
    }
private:
    void change(vector<int>& input, int begin, int end)
    {
        int root = input[begin];
        while((begin << 1) + 1 <= end) 
        {
            int child = (begin << 1) + 1;
            if(child + 1 <= end) {
                if (input[child] < input[child+1])
                    child++;
            } 
            if (root < input[child]) {
                std::swap(input[begin], input[child]);
                begin = child;
            } else 
                break;
        }
    }
};


int main()
{
    //int vec[]={11, 9, 5, 8, 4, 7 ,3, 2, 6, 11, 2, 3, 43, 12};
    int vec[]={4,5,1,6,2,7,3,8};
    std::vector<int> arr(std::begin(vec), std::end(vec));
    Solution so;
    std::vector<int> Res = so.GetLeastNumbers_Solution(arr, 4);
    for (auto var : Res)
        printf("%d ", var);
    printf("\n");
    return 0;
}
