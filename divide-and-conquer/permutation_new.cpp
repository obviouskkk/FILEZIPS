/* ***********************************************************************

  > File Name: permutation_new.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Mar 2018 03:18:53 PM CST

 ********************************************************************** */

#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using std::vector;
using std::string;
class Solution {
 public:
    void PermutationD(std::unordered_set<std::string>& Res, string str, int begin, int end) {
        if (begin >= end) return;
        if (end == begin + 1) {
            Res.insert(str);
        }
        for (int i = begin; i < end; ++i) {
            std::swap(str[begin], str[i]);
            PermutationD(Res, str, begin + 1, end);
            std::swap(str[begin], str[i]);
        }
    }

    vector<string> Permutation(string str) {
        vector<string>  Res;
        if (str.empty())
            return Res;
        std::sort(str.begin(), str.end());
        std::unordered_set<std::string> myset;
        PermutationD(myset, str, 0, str.size());
        vector<string> ret(std::begin(myset), std::end(myset));
        return ret;
    }
};


int main()
{
    std::string str = "ab";
    Solution su;
    std::vector<string>  Res = su.Permutation(str);
    for (auto str : Res)
        printf("%s", str.c_str());
    return 0;
}
