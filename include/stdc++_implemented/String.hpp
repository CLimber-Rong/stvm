/*
	Name:
	Copyright:
	Author:
	Date: 29/07/23 12:59
	Description:
*/
#ifndef STRING
#define STRING

#include "string.h"
#include "string"

using namespace std;

class String
{
	string str;

public:
	String();			   //初始化为空字符串
	String(char *s);	   //初始化，将s复制到this
	bool equals(String s); //判断this的内容是否与s相等，是则返回true，否则返回false

	//以下的一系列toString函数会将不同的数据类型转为String后保存到this当中，返回this
	String toString(int value);
	String toString(bool value);
	String toString(float value);
	String toString(double value);

	int length();			   //返回字符串长度
	char at(int index);		   //返回第index个字符
	void c_arr(char *s);	   //将this复制到s里
	bool match_head(String s); //从头开始匹配s，匹配成功返回true，否则返回false
	/*为了实现String添加的新函数*/
	string getstring(); //返回自身的string
};

String::String()
{
	str = "";
}

String::String(char *s)
{
	str = s;
}

bool String::equals(String s)
{
	return s.getstring() == str;
}

String String::toString(int value)
{
	str = to_string(value);
	return *this;
}

String String::toString(bool value)
{
	str = to_string(value);
	return *this;
}

String String::toString(float value)
{
	str = to_string(value);
	return *this;
}

String String::toString(double value)
{
	str = to_string(value);
	return *this;
}

int String::length()
{
	return str.size();
}

char String::at(int index)
{
	return str.at(index);
}

bool String::match_head(String s)
{
	//用于匹配s
	if (str.size() < s.length())
	{
		return false;
		//显然，str的长度必须大于s才有可能匹配成功
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (str[i] != s.getstring()[i])
		{
			return false;
		}
	}
	return true;
}

#endif
