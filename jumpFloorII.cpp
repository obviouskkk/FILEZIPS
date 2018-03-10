/* ***********************************************************************

  > File Name: jumpFloorII.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 06:13:48 PM CST

 ********************************************************************** */
/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * */
// 即 fn = fn-1 + fn-2 + fn -3 + f2 + f1；
//
class Solution {
public:
    int jumpFloorII(int number) {
        int ret = 1;
        if (number < 1)
            return 0;
        for (int i = 1; i < number ; i++) {
            ret *= 2;
        }
        return ret;
    }
};

