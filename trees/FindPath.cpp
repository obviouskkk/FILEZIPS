/* ***********************************************************************

  > File Name: FindPath.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 17 Mar 2018 03:28:21 PM CST

 ********************************************************************** */


/*
 * 输入一颗二叉树和一个整数，
 * 打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 *
 */
#include <vector>
#include <cstdio>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// AC
using std::vector;
class Solution {
public:
    void AddPath(vector<vector<int> > & ret, 
                 vector<int> & akPathvec, 
                 TreeNode* root, 
                 int expectNumber)
    {
        if (root == NULL)
            return;
        akPathvec.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (expectNumber == root->val) {
                ret.push_back(akPathvec);
            } 
            akPathvec.pop_back();
            return;
        }
        expectNumber -= root->val;
        if (root->left) {
            AddPath(ret, akPathvec, root->left, expectNumber);
        }
        if (root->right) {
            AddPath(ret, akPathvec, root->right, expectNumber);
        }
        akPathvec.pop_back();
    }

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
    {
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;
        vector<int> akPathvec;
        AddPath(ret, akPathvec, root, expectNumber);
        return ret;
    }
};
