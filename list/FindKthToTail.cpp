/* ***********************************************************************

  > File Name: FindKthToTail.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 08:15:21 PM CST

 ********************************************************************** */

// 输入一个链表，输出该链表中倒数第k个结点。
#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL) return NULL;
        if (k == 0) return NULL;
        ListNode* leader = pListHead;
        unsigned int i = 1;
        for (; leader && leader->next != NULL && i < k; ++i) {
            leader = leader->next;
        }
        if (i < k)
            return NULL;
        ListNode* ret = pListHead;
        while (leader && leader->next != NULL) {
            leader = leader->next;
            ret =ret->next;
        }
        return ret;

    }
};
