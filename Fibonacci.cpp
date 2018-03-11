/* ***********************************************************************

  > File Name: Fibonacci.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 05:44:33 PM CST

 ********************************************************************** */

#include <stdio.h>

/*
struct FN{
    int fn_1;
    int fn_2;

};
class Solution {
public:
    FN FibonacciSelf(int n)
    {
        FN ret;
        if (n == 3) {
            ret.fn_1 = 1;
            ret.fn_2 = 2;
        } else {
            ret.fn_1 = FibonacciSelf(n-1).fn_2;
            ret.fn_2 = FibonacciSelf(n-1).fn_2 + FibonacciSelf(n-1).fn_1;
        }
        return ret;
    }

    int Fibonacci(int n) {
        if (n == 1 || n == 2)
            return 1;
        else return FibonacciSelf(n).fn_2;

    }
};
*/

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2)
            return 1;
        int i = 3 ;
        int pre1 = 1;
        int pre2 = 2;
        while (i <= n) {
            int tmp = pre2 ;
            pre2 = pre2 + pre1;
            pre1 = tmp ;
            i ++;
        }
        return pre2;
    }
};


int  main ()
{
    Solution a;
    printf("%d\n", a.Fibonacci(52));
}
