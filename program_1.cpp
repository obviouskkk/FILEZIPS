/* ***********************************************************************

  > File Name: program_1.cpp
  > Author: zzy
  > Mail: zzy@taomee.com 
  > Created Time: Tue 26 Sep 2017 04:26:18 PM CST
  > 判断一个字符串的字符集是否在另一个字符串连续出现

 ********************************************************************** */

#include <iostream>
#include <string>

enum { CHRS = 256 };

class char_set
{
	friend std::ostream & operator << (std::ostream& os, const char_set &stra)
	{
		for (int i = 0; i < 256 ;++i)
		{	
			if(stra.sets[i] != 0){
				os << char(i)<< ":" << stra.sets[i] <<" ";
			}
		}
		os << std::endl;
	}
public:
	char_set(std::string & strb):sets(new int[CHRS]() )
	{	
		std::string::iterator it = strb.begin();
		for ( ;it != strb.end() ;it++)
		{
			sets[*it] ++;
		}
	}

	char_set(char* strb, std::size_t length )
	{
		for (std::size_t i = 0; i < length ;i++)
		{
			sets[*strb] ++;
			strb++;
		}
	}

	bool operator !=(const char_set& setb)
	{	
		for (int i = 0; i < CHRS ; i++)
		{
			if (this->sets[i] != setb.sets[i])
				return false;
		}
		return true;
		
	}

private:
	int *sets; 
};




int main(int argc, const char* argv[])
{	
	std::string stra("helloworld");
	std::string strb("lol");
	char_set csa(stra);
	char_set csb(strb);
	std::cout << csa ;
	std::cout << csb ;
	if ( csa != csb )
		std::cout << "" <<std::endl;
    return 0;
}

