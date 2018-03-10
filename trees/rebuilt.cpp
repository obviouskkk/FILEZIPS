/* ***********************************************************************

  > File Name: rebuilt.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 05:00:09 PM CST

 ********************************************************************** */


#include <cstdio>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTreeSelf(pre, 0, pre.size()-1,  vin, 0, vin.size()-1);
    }
    TreeNode* reConstructBinaryTreeSelf(
        vector<int> pre, int pre_left, int pre_right, 
        vector<int> vin, int vin_left, int vin_right) {
        if (pre_left > pre_right || vin_left > vin_right) {
            return NULL;
        }
        // 根节点
        TreeNode* root =new TreeNode(pre[pre_left]);
        for (int i = vin_left; i <= vin_right ; ++i) {
            if (vin[i] == pre[pre_left]) { // 中序的根节点
                root->left = reConstructBinaryTreeSelf (
                    pre, pre_left + 1, pre_left + i - vin_left, // 根节点后面N个都是左子树 N = 找到中序根的位置减起点位置
                    vin, vin_left, i - 1); // 中序开始到根节点之前都是左子树
                root->right = reConstructBinaryTreeSelf (
                    pre, pre_left + i - vin_left + 1, pre_right, // 刚才剩下的都是右子树
                    vin, i + 1, vin_right 
                    );
            }
        }
        return root;
    }
};
