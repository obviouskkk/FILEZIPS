/* ***********************************************************************

  > File Name: Find_set.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 12 Mar 2018 08:55:56 PM CST

 ********************************************************************** */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

int father[10],a,b;
int find(int x){
	if(father[x] != x)
		x = find(father[x]);
	return x;
}


int main()
{
	int i;
    int n , m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		father[i] = i;
    printf("输入亲戚关系:\n");
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d",&a ,&b);
		a = find(a);
		b = find(b);
		father[a] = b;
        for (auto i : father) {
            printf("%d ", i);
        }
	}
    printf("输入亲戚关系:\n");
    scanf("%d %d", &a, &b);
    a=find(a);
    b=find(b);
    if(a == b)
        printf("Yes\n");
    else
        printf("No\n");
	return 0;
}
