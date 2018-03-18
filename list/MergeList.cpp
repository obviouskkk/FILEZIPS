/* ***********************************************************************

  > File Name: MergeList.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 08:53:29 PM CST

 ********************************************************************** */

/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，
 * 当然我们需要合成后的链表满足单调不减规则。
 * 
*/

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* ret = NULL;
        if (pHead1 == NULL && pHead2 == NULL)
            return NULL;
        else if (pHead1 == NULL)
            return pHead2;
        else if (pHead2 == NULL)
            return pHead1;
        if (pHead1->val < pHead2->val) {
            ret = pHead1;
            pHead1 = pHead1->next;
        } else {
            ret = pHead2;
            pHead2 = pHead2->next;
        }
        ListNode* pre = ret;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                pre ->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                pre ->next = pHead2;
                pHead2 = pHead2->next;
            }
            pre = pre->next;
        }
        if (pHead1) pre->next = pHead1;
        if (pHead2) pre->next = pHead2;
        return ret;
    }
};
