#include <iostream>
#include <string>
#include <string_view>
#include <cassert>
#include <cstring>
#include <vector>


std::vector<int> getNext(std::string_view T)
{
	int i = 0;
    std::vector<int> next(T.length());
	next[0] = 0;
	int j =0;
	while(i<T.length())
    {
        ++i;
        ++j;
        if(T[i]!=T[j])
        {
            next[i]=j;
        }
        else
        {
            next[i]=next[j];
        }
    }
    return next;
}

/// @brief KMP算法，时间复杂度O(m+n)
/// @param S 主串
/// @param T 子串
/// @param pos 主串中查找的起始位置
/// @return 子串在主串第pos个字符开始第一次出现的位置，若不存在=则返回为-1
int KMP(std::string_view S,std::string_view T,int pos)
{
	assert(!T.empty());
	assert(!S.empty() && S.length()>=pos);

	int i=pos;
	int j=0;

    auto next = getNext(T);

	while(i<=S.length() && j<T.length())
	{
		if(j==0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j=next[j];
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
	std::cout<<KMP(str1,"[index]",0)<<std::endl;
	std::cout<<std::strstr(str1.c_str(),"[index]")<<std::endl;
	return 0;
}