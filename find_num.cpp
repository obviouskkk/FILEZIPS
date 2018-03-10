/* ***********************************************************************

  > File Name: find_num.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 05:36:15 PM CST

 ********************************************************************** */


#include <stdio.h>
#include <vector>

using std::vector;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        auto itr = rotateArray.begin();
        int min = *itr;
        while (itr != rotateArray.end()) {
            if (*itr < min)
                return *itr;
            itr++;
        }
        return min;
    }
};
