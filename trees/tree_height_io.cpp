/* ***********************************************************************

  > File Name: tree_height.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 22 Feb 2018 01:21:47 PM CST

 ********************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>

struct Node
{
    Node(int i){
        data  = i;
    }
    int data;
    Node* pleft;
    Node* pright;
};

class tree
{
public:
    Node *find_node(int data);
private:
    Node* proot;
};

int main()
{
	std::string tmp;
	std::vector< std::vector<std::string>  > input_info; 
	while ( getline(std::cin, tmp) )
	{
		std::vector<std::string> input_tmp;
		std::istringstream istring(tmp);
		std::string  s;
		while (istring >> s){
			input_tmp.push_back(s);
		}
		input_info.push_back(input_tmp);
		tmp="";
	}
    
    auto itr= input_info.begin();
    int line_num = std::stoi((*itr)[0]);
    int buf[1000] = {0};
    itr ++;
    while (itr != input_info.end() ){
        auto itr_end = (*itr).rbegin();
        auto itr_begin = (*itr).begin();
        buf[std::stoi(*itr_end)] += buf[std::stoi(*itr_begin)];
        buf[std::stoi(*itr_end)] ++;
        itr ++;
    }
    int height = 0;
    for (int i = 0; i < line_num ;i++){
        if (buf[i]) 
            printf("%d:%d\n", i, buf[i]);
        if (buf[i] > height)
            height = buf[i];
    }
    printf("%d\n", height + 1);
    return 0; 
}

