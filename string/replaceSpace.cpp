/* ***********************************************************************

  > File Name: replaceSpace.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 04:29:44 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <string.h>

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int space_num = 0, index = 0;
        while(index <= length) {
            if(*(str+index) ==' ') {
                space_num ++;
            }
            index ++;
        }
        if (space_num == 0)
            return;
        int new_length = length + 2 * space_num;
        while(length >= 0) {
            if (str[length] == ' ') {
                str[new_length -- ] = '0';
                str[new_length -- ] = '2';
                str[new_length] = '%';
            } else {
                str[new_length] = str[length];
            }
            length --;
            new_length --;
        }
    }
};

int main()
{
    char arr[100] = {"hello world"};
    Solution a;
    a.replaceSpace(arr, strlen(arr));
    printf("%s\n", arr);
}
