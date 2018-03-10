/* ***********************************************************************

  > File Name: replace_space.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 05 Mar 2018 08:21:28 PM CST

 ********************************************************************** */

/*
 * Wrong Code
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory>

/*
char* replace(char arr[])
{
    int space_num = 0;
    for (int i = 0; i <= (int)strlen(arr); ++i) {
        if (arr[i] == ' ') {
            space_num ++;
        }
    }
    size_t new_size = strlen(arr) + 2 * space_num + 1;
    char * ret = (char*)realloc(arr, new_size);
    if (ret == NULL)
        return NULL;
    int old_size =  strlen(arr) + 1;
    for (int i = new_size -1; i > 0 && old_size > 0; --i) {
        if (arr[old_size] == '\n') {
            arr[--new_size ] = '0'; 
            arr[--new_size ] = '2';
            arr[--new_size ] = '%';
        } else {
            arr[--new_size] = arr[old_size --];
        }
    }
    return ret;
}
*/

char* replace(char arr[])
{
    int space_num = 0;
    for (int i = 0; i <= (int)strlen(arr); ++i) {
        if (arr[i] == ' ') {
            space_num ++;
        }
    } 
    size_t new_size = strlen(arr) + 2 * space_num + 1;
    char * ret = (char*)realloc(arr, new_size);
    if (ret == NULL)
        return NULL;
    int old_size =  strlen(arr) + 1;
    for (int i = new_size -1; i > 0 && old_size > 0; --i) {
        if (ret[old_size] == '\n') {
            ret[--new_size ] = '0'; 
            ret[--new_size ] = '2';
            ret[--new_size ] = '%';
        } else {
            ret[--new_size] = ret[old_size --];
        }
    }
    return ret;
}


int main()
{
    char arr[] = "hello world hello";
    printf("%s\n", replace(arr));

}
