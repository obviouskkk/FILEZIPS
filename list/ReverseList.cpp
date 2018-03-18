/* ***********************************************************************

  > File Name: ReverseList.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 08:36:31 PM CST

 ********************************************************************** */

// 输入一个链表，反转链表后，输出链表的所有元素。
//
//
//
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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* ret =  ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = NULL;
        return ret;
    }
};
