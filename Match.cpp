/************************************************************************/
/*实现一个函数用来匹配包含‘.’和‘*’的正则表达式。
/*模式串‘.’表示任意一个字符，而‘*’表示它前面的字符可以出现任意次（包含0次）
/*例如：字符串“aaa”与模式“a.a”和“ab*ac*a”匹配，但与“aa.a”及“ab*a”均不匹配
/************************************************************************/

#include <iostream>

using namespace std;

bool matchCore(char* str, char* pattern);

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
		else
			return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}

int main()
{
	char str[100];
	char pattern[100];
	cin >> str;
	cin >> pattern;
	cout << match(str, pattern) << endl;

	system("pause");
	return 0;
}
