/* ***********************************************************************

  > File Name: FindInOrderArray.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 02:01:10 PM CST

 ********************************************************************** */

#include <vector>
#include <cassert>
#include <stdio.h>

class Solution {
public:
    bool Find(int target, std::vector<std::vector<int> > &array) {
        if (array.empty())
            return false;
        int row = array[0].size();
        int line = array.size()- 1;
        for (int i = line, j = 0; i >= 0 && j < row ; ) {
            if (array[i][j] == target) {
                return true;
            }
            if (array[i][j] > target) {
                i--;
                continue;
            }
            if (array[i][j] < target) {
                j++;
                continue;
            }
        }
        return false;
    }
};

int main()
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    std::vector<int> vec2;
    vec2.push_back(7);
    vec2.push_back(8);
    vec2.push_back(9);
    std::vector<int> vec3;
    vec3.push_back(4);
    vec3.push_back(5);
    vec3.push_back(6);
    std::vector<std::vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec3);
    vec.push_back(vec2);
    Solution cl;
    if (cl.Find(4, vec)) {
        printf("found\n");
    }
}


