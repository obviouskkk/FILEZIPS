/* ***********************************************************************

  > File Name: preOrderNormal.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 17 Mar 2018 07:52:27 PM CST

 ********************************************************************** */

// 二叉树
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>

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
std::vector<int> preOrderNormal(TreeNode* pRoot)
{
    std::vector<int>  VCiRet;
    if (pRoot == NULL) return VCiRet;
    std::stack<TreeNode*> STpNode;
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
    return VCiRet;
}

// 中序遍历
// 左边的一直入栈，到叶子就打印然后回退
std::vector<int> InOrderNormal(TreeNode* pRoot)
{
    std::vector<int>  VCiRet;
    std::stack<TreeNode*> STpNode;
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
    return VCiRet;
}

// 后续遍历
std::vector<int>  TPosOrderNormal(TreeNode* pRoot)
{
    std::vector<int> Ret;
    if (pRoot == NULL)
        return Ret;
    std::stack<TreeNode*> iStack;
    iStack.push(pRoot);
    TreeNode* curr = pRoot;
    while (!iStack.empty()) {
        TreeNode* pTop = iStack.top();
        if(pTop->left != NULL && pTop->left != curr && pTop->right != curr) {
            iStack.push(pTop->left);
        } else if(pTop->right != NULL && curr != pTop->right) {
            iStack.push(curr->right);
        } else{
            iStack.pop();
            curr = pTop;
            Ret.push_back(curr->val);
        }
    }
    return Ret;
}

// 层序遍历
// 一个队列，每次放入队首元素的左节点和右节点
std::vector<int> LevelOrderNormal(TreeNode* pRoot)
{
    std::vector<int> Ret;
    if (pRoot == NULL)
        return Ret;
    std::queue<TreeNode*> NodeQueue;
    NodeQueue.push(pRoot);
    while (!NodeQueue.empty()) {
        TreeNode* HeadNode  = NodeQueue.front();
        if (HeadNode->left)
            NodeQueue.push(HeadNode->left);
        if (HeadNode->right)
            NodeQueue.push(HeadNode->right);
        // HeadNode
        NodeQueue.pop();
        Ret.push_back(HeadNode->val);
    }
    return Ret;
}




