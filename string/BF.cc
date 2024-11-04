#include <iostream>
#include <string>
#include <string_view>
#include <cassert>
#include <cstring>

/// @brief BF算法，时间复杂度 O(m*n)
/// @param S 主串
/// @param T 子串
/// @param pos 主串中查找的起始位置
/// @return 子串在主串第pos个字符开始第一次出现的位置，若不存在=则返回为-1
int BF(std::string_view S,std::string_view T,int pos)
{
	assert(!T.empty());
	assert(!S.empty() && S.length()>=pos);

	int i=pos;
	int j=0;
	while(i<=S.length() && j<T.length())
	{
		if(S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i-j+1;
			j=0;
		}
	}
	if(j >= T.length())
	{
		return i-T.length();
	}

	return -1;
}

int main()
{
	std::string str1 = "123abc456aaa777[index]ccsss888999sda";
	std::cout<<BF(str1,"[index]",0)<<std::endl;
	std::cout<<std::strstr(str1.c_str(),"[index]")<<std::endl;
	return 0;
}