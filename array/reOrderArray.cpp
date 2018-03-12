/* ***********************************************************************

  > File Name: reOrderArray.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 08:05:52 PM CST

 ********************************************************************** */
/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */

#include <vector>
using std::vector;
class Solution {
 public:
    void reOrderArray(vector<int> &array) {
        std::vector<int> arr_1;
        std::vector<int> arr_2;
        for (auto itr = array.begin(); itr != array.end(); ++itr) {
            if (*itr % 2 == 0)
                arr_1.push_back(*itr);
            else 
                arr_2.push_back(*itr);
        }
        for (auto itr = arr_2.begin(); itr != arr_2.end(); ++itr) {
            arr_1.push_back(*itr);
        }
        std::swap(array, arr_1);
    }
};
