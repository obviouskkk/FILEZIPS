/* ***********************************************************************

  > File Name: two_stack_for_queue.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Mar 2018 05:24:51 PM CST

 ********************************************************************** */

#include <stack>
#include <vector>
#include <cstdio>

using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while (!stack1.empty()) {
            int node = stack1.top();
            stack2.push(node);
            stack1.pop();
        }
        int ret = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            int node = stack2.top();
            stack2.pop();
            stack1.push(node);
        }
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
