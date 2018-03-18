/* ***********************************************************************

  > File Name: printListFromTailToHead.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 23 Feb 2018 11:34:12 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

//递归
class Solution {
public:
    void print (ListNode* head, std::vector<int> & vec){
        if (head->next) print(head->next, vec);
        vec.push_back(head->val);
    }
    std::vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> res;
        print(head, res);
        return res;
    }
};
/*
class Solution {
public:
    void print (ListNode* head, std::vector<int> & vec){
        if ( NULL == head->next) return vec.push_back(head->val);
        else return print(head->next, vec), vec.push_back(head->val);
    }
    std::vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> res;
        print(head, res);
        return res;
    }
};
*/

int main()
{
	struct ListNode ListNode1(1);
	struct ListNode ListNode2(2);
	struct ListNode ListNode3(3);
	ListNode1.next = & ListNode2;
	ListNode2.next = & ListNode3;
	Solution a;
	std::vector<int> res_vec = a.printListFromTailToHead(&ListNode1);
    auto it = res_vec.begin();
    while (it != res_vec.end()) {
        printf("%d ",*it);
        ++ it;
    }
	return 0;
}


