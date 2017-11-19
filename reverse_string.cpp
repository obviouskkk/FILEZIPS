/* ***********************************************************************

  > File Name: reverse_string.cpp
  > Author: zzy
  > Mail: zzy@taomee.com 
  > Created Time: Sun 19 Nov 2017 05:01:49 PM CST

 ********************************************************************** */

#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
#include <cstdio>

char * reverse_string_recursion(char* string ,int begin ,int end)
{	
	if (begin < end){
		char tmp = string[begin];
		*(string + begin) = *(string + end);
		*(string + end) = tmp ;
		return reverse_string_recursion(string, begin+1 ,end-1);
	} else{
		return string;
	}
}

char *reverse_string(char * string)
{
	int len = strlen(string) - 1;
	return reverse_string_recursion(string, 0, len);
}


int main(int argc, const char* argv[])
{
	char str[] = "hello how are you?";
	//char* str = "hello how are you?"; //why it is wrong
	printf("%s",reverse_string(str));
    return 0;
}

