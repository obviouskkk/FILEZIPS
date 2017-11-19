/* ***********************************************************************

  > File Name: n_power.cpp
  > Author: zzy
  > Mail: zzy@taomee.com 
  > Created Time: Sun 19 Nov 2017 04:44:08 PM CST
  > 递归实现n的k次方
 ********************************************************************** */

#include <iostream>
#include <cstdio>

//仍有可能越界
long long int n_power(int n, int k)
{
	if(k < 1)
		return 1;
	else if (k == 1)
		return n;
	else return n*n_power(n, k - 1);
}


int main(int argc, const char* argv[])
{
	int n , k ;
	std::cin >> n ;
	std::cin >> k;
	printf("%d的%d次方是%ld\n",n, k, n_power(n, k));
    return 0;
}

