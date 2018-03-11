/* ***********************************************************************

  > File Name: share_apple.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 22 Feb 2018 03:43:51 PM CST

 ********************************************************************** */
/*
题目描述
    n只奶牛坐在一排，每个奶牛拥有 ai 个苹果a,
    现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，
    每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
    问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
输入描述:
    每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），
    接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
输出描述:
    输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
*/
#include <iostream>
#include <stdio.h>

int move_times(int * a, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    if (sum % length != 0)
        return -1;
    int final_num = sum / length;
    int ret = 0;
    for (int i = 0; i < length; i++) {
        int gap = a[i] > final_num ? a[i] - final_num : final_num - a[i];
        if (gap % 2 != 0)
            return -1;
        ret += gap / 2;
    }
    return ret / 2;
}

int main(int argc, const char* argv[])
{
    int length ;
    scanf("%d", &length);
    int ai;
    int* a = (int *)malloc(sizeof(int) * length);
    for (int i = 0 ; i < length; i++) {
        scanf("%d", &ai);
        a[i] = ai;
    }
    printf("%d\n", move_times(a, length));
    free(a);
    return 0;
}

