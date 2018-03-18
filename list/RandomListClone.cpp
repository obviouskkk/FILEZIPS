/* ***********************************************************************

  > File Name: RandomListClone.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 17 Mar 2018 04:08:24 PM CST

********************************************************************** */
#include <stdio.h>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
        }
};

/*  is error
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        RandomListNode* NewHead = new RandomListNode(pHead->label);
        NewHead->next = pHead->next;
        NewHead->random = pHead->random;

        NewHead->next = Clone(NewHead->next);
        return NewHead;
    }
};
*/

// 在每个节点后面插入一个节点的复制，然后拆分链表
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) 
            return NULL;
        RandomListNode* NewIter = NULL;
        RandomListNode* OldIter = pHead;
        // 复制双份
        while (OldIter != NULL) {
            NewIter = new RandomListNode(OldIter->label);
            NewIter->next = OldIter->next;
            OldIter->next = NewIter;
            OldIter = NewIter->next;
        }
        // 加上随机节点
        OldIter = pHead;
        while (OldIter) {
            NewIter = OldIter->next;
            if (OldIter->random)
                NewIter->random = OldIter->random->next;
            OldIter = NewIter->next;
        }
        // 拆分
        OldIter = pHead;
        RandomListNode* NewHead = pHead->next;
        while (OldIter->next) {
            NewIter = OldIter->next;
            OldIter->next = NewIter->next;
            OldIter = NewIter;
        }
        return NewHead;
    }
};












