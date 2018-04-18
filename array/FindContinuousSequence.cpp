/* ***********************************************************************

  > File Name: FindContinuousSequence.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 18 Apr 2018 11:00:28 PM CST

 ********************************************************************** */

#include <bits/stdc++.h>

// 暴力法 AC
class Solution {
public:
    std::vector<std::vector<int> > FindContinuousSequence(int sum) {
        std::vector<std::vector<int> > ret_vec;
        int tmp_sum = 0;
        std::vector<int> tmp_vector;
        for (int i = 1; i < sum; ++i){
            for(int j = i ; j < sum; ++j) {
                tmp_sum += j;
                tmp_vector.push_back(j);
                if (tmp_sum == sum) {
                    ret_vec.push_back(tmp_vector);
                } else if (tmp_sum > sum) {
                    tmp_vector.clear();
                    tmp_sum = 0;
                    break;
                }
            }
        }
        return ret_vec;
    }
};


int main()
{
    Solution s;
    std::vector<std::vector<int> > ret_vec = s.FindContinuousSequence(9);
    for (auto vec : ret_vec) {
        for (auto num : vec) {
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}



