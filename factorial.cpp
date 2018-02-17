/* ***********************************************************************

  > File Name: factorial.cpp
  > Author: zzy
  > Mail: zzy@taomee.com 
  > Created Time: Sun 19 Nov 2017 04:43:05 PM CST
  > 递归实现n的阶乘
 ********************************************************************** */

#include <iostream>
#include <cassert>
#include <cstdio>

long long unsigned int  factorial(int n)
{
	assert(n >= 2 );
	if(n == 2 )
		return  2;
	else return n*factorial(n-1);
}

int main(int argc, const char* argv[])
{
	int n;
	std::cin >> n;
	printf("%d的阶乘是%llu", n, factorial(n));
    return 0;
}

