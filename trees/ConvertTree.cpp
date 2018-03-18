/* ***********************************************************************

  > File Name: ConvertTree.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 17 Mar 2018 05:36:24 PM CST
********************************************************************** */

#include<cstdio>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};

#include <queue>
class Solution {
public:
    void pushStack(std::queue<TreeNode*>& stack, TreeNode* pRootOfTree)
    {   
        if (!pRootOfTree) 
            return;
        if (pRootOfTree->left) {
            pushStack(stack, pRootOfTree->left);
        } 
        stack.push(pRootOfTree);
        if (pRootOfTree->right) {
            pushStack(stack, pRootOfTree->right);
        }
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)
            return NULL;
        if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree;
        std::queue<TreeNode*> queue;
        pushStack(queue, pRootOfTree);
        TreeNode* now = queue.front();
        TreeNode* prev = NULL;
        TreeNode* ret = now;
        ret->left = NULL;
        while (now || !queue.empty()) {
            queue.pop();
            prev = now;
            now = queue.front();
            if (now) now->left = prev;
            prev->right = now;
        }
        return ret;
    }
};









