/* ***********************************************************************

  > File Name: TreeDepth.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 15 Apr 2018 01:29:15 PM CST

 ********************************************************************** */
#include <cstdio>
#include <algorithm>

/*
 *  求树的高度
 *  nowcooder AC ; https://www.nowcoder.com/profile/2616737/codeBookDetail?submissionId=25250380
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        return std::max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) +1;
    }
};
