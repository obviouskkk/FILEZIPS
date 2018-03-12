/* ***********************************************************************

  > File Name: Solution.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 23 Feb 2018 10:39:16 PM CST

 ********************************************************************** */
/*
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <vector>
using namespace std;
class Solution {
 public:
	 bool Find(int target, vector<vector<int> > array) {
         if (array.empty())
             return false;
         int row_high = array[0].size() - 1, line_low = 0;
         while (row_high >= 0 && line_low < (int)array.size()) {
             if (array[line_low][row_high] == target)
                 return true;
             else if (array[line_low][row_high] > target)
                 -- row_high;
             else 
                 ++ line_low;
         }
         return false;
     }
};
