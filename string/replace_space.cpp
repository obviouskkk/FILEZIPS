/* ***********************************************************************

  > File Name: replace_space.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 07 Mar 2018 01:37:51 PM CST

 ********************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void replace(char arr[])
{
    int space_num = 0;
    for (int i = 0; i <= (int)strlen(arr); ++i) {
        if (arr[i] == ' ') {
            space_num ++;
        }
    }
    size_t new_size = strlen(arr) + 2 * space_num + 1;
    int old_size = strlen(arr) ;
    arr[new_size -- ] = '\0';
    for (int i = new_size - 1; i > 0 && old_size > 0;) {
        if (arr[old_size--] == ' ') {
            arr[i--] = '0'; 
            arr[i-- ] = '2';
            arr[i-- ] = '%';
        } else {
            arr[i--] = arr[old_size --];
        }
    }
}

int main()
{
    char arr[100] = "hello world";
    replace(arr);
    printf("%s\n", arr);

}
