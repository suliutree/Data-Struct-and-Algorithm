/************************************************************************/
/* 删除字符串中所有给定的子串                                            */
/************************************************************************/
#include <iostream>
#include <string.h>

using namespace std;

int del_sub_str(const char* str, const char* sub_str, char* result_str)
{
	if (str == NULL)
	{
		result_str = NULL;
		return 0;
	}

	int count = 0;
	int str_len = strlen(str);
	int sub_str_len = strlen(sub_str);
	
	if (str_len < sub_str_len || sub_str == NULL)
	{
		strcpy(result_str, str);
		return 0;
	}

	while (*str != '\0')
	{
		while (*str != *sub_str && *str != '\0')
		{
			*result_str++ = *str++;
		}
		if (*str != '\0')
		{
			if (strncmp(str, sub_str, sub_str_len) != 0)
			{
				*result_str++ = *str++;
				continue;
			}
			else
			{
				count++;
				str += sub_str_len;
			}
		}
	}

	*result_str = '\0';
	return count;
}

int main()
{
	char str[] = "abcde123abcd123";
	char sub_str[] = "123";
	char result_str[100];
	int count = del_sub_str(str, sub_str, result_str);
	cout << result_str << endl;
	cout << count << endl;
	system("pause");
	return 0;
}
