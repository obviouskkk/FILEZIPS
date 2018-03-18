/* ***********************************************************************

  > File Name: printList.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 04:46:22 PM CST

 ********************************************************************** */

#include <vector>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};


using namespace std;
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        static std::vector<int> ret;
        if (head->next) {
            printListFromTailToHead(head->next);
            ret.push_back(head->val);
        } else {
            ret.push_back(head->val);
        }
        return ret;
    }
};
