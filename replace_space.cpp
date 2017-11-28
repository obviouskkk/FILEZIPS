/* ***********************************************************************

  > File Name: replace_space.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 Nov 2017 09:43:54 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <string.h>

char* replace_space(char str[], int length) //length is allow length
{
	assert(str);
	int new_length = 0, real_length = strlen(str);
	for(int i = 0; i < real_length; i++){
		if( *(str+i) == ' ' )
			new_length += 2;
	}
	new_length += real_length;
	if(new_length > length)
		return NULL;
	str[new_length-- ] = '\0';
	--real_length;
	while(new_length && real_length ){
		if( (str[new_length] = str[real_length]) == ' ' ){
			str[new_length--] = '0';
			str[new_length--] = '2';
			str[new_length] = '%';
		}
		new_length --;
		real_length --;
	}
	return str;
}


int main(int argc, const char* argv[])
{
	char buf[1024];
	while(fgets(buf, 1024, stdin) != NULL ){
		if(buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = '\0';
		printf("%s\n",replace_space(buf,1024) );
	}
    return 0;
}

