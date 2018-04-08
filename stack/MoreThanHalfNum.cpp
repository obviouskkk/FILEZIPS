/* ***********************************************************************

  > File Name: MoreThanHalfNum.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Mar 2018 04:16:55 PM CST

 ********************************************************************** */

/*
 * 数组中有一个数字出现的次数超过数组长度的一半，
 * 请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，
 * 因此输出2。如果不存在则输出0。
 */

/*
 * 借助一个栈
 * 循环整个数组:
 * 栈空的时候入栈
 * 如果等于栈顶元素，入栈。
 * 不相等出栈
 * 最后check一次
*/
#include <vector>
#include <stack>

using std::vector;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) 
            return 0;
        int times = 1, ret = numbers[0];
        int size = numbers.size();
        for (int i = 0; i < size; ++i) {
            if (times > 0) {
                if (numbers[i] == ret) {
                    times++;
                } else 
                    -- times;
            } else if (times == 0) {
                ret = numbers[i];
                times = 1;
            } else { // 小于0的时候，持续减
                -- times;
            }
        }
        if (size % 2 != 0 && times > 0) return ret;
        int check_times = 0;
        for (int i = 0; i < (int)numbers.size(); ++i) {
            if (numbers[i] == ret) 
                check_times ++;
        }
        if (check_times > (size<<1) )
            return ret;
        return 0;
    }
};



