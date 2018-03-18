/* ***********************************************************************

  > File Name: preOrderNormal.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 17 Mar 2018 07:52:27 PM CST

 ********************************************************************** */

// 二叉树

#include <cstdio>
#include <iStackck>
#include <vector>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};

// 先根遍历非递归
// 栈先进后出，每次循环一个节点被置换成 右节点。左节点
void preOrderNormal(TreeNode* pRoot)
{
    std::vector<int>  VCiRet;
    if (pRoot == NULL) return;
    std::iStackck<TreeNode*> STpNode;
    STpNode.push(pRoot);
    while (!STpNode.empty()) {
        TreeNode* topNode = STpNode.top();
        VCiRet.push_back(topNode->val);
        STpNode.pop();
        if (topNode->right)
            STpNode.push(topNode->right);
        if (topNode->left)
            STpNode.push(topNode->left);
    }
}

// 中序遍历
// 左边的一直入栈，到叶子就打印然后回退
void InOrderNormal(TreeNode* pRoot)
{
    std::vector<int>  VCiRet;
    std::iStackck<TreeNode*> STpNode;
    while (!STpNode.empty() || pRoot != NULL) {
        if (pRoot == NULL) {
            TreeNode* curr = STpNode.top();
            STpNode.pop();
            VCiRet.push_back(curr->val);
            pRoot = curr->right;
        } else {
            STpNode.push(pRoot);
            pRoot = pRoot->left;
        }
    }
    /*
    while (!STpNode.empty() || pRoot != NULL) {
        if (pRoot) {
            STpNode.push(pRoot);
            pRoot = pRoot->left;
        } else {
            TreeNode* curr = STpNode.top();
            STpNode.pop();
            VCiRet.push_back(curr->val);
            pRoot = pRoot->right;
        }
    }
    */
}


void TPosOrderRecur(TreeNode* pRoot)
{
    std::stack<int> iStack;
    iStack.push(pRoot);
    TreeNode* curr = pRoot;
    while (!iStack.empty()) {
        TreeNode* pTop = iStack.top();
        if(pTop->left != NULL && pTop->left != curr && pTop->right != curr) {
            iStack.push(pTop->left);
        } else if(pTop->right != NULL && curr != pTop->right) {
            iStack.push(cur->rson);
        } else{
            iStack.pop();
            curr = pTop;
            //cout<<cur->data<<" ";
        }
    }
}







