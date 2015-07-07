#include <iostream>

using namespace std;

enum status {kValid, kInvalid};
int g_nStatus = kValid;

long long StrToIntCore(const char* str, bool minus);

int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long num = 0;

	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			minus = true;
			str++;
		}

		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}

	return (int)num;
}

// num定义为 long long 类型是为了判断其在 int 范围内是否溢出
long long StrToIntCore(const char* str, bool minus)
{
	long long num = 0;

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*str - '0');

			// 一定要在0x80000000前面加上 signed int，否则默认为无符号数
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if (*str == '\0')
		g_nStatus = kValid;

	return num;
}


int main()
{
	char str1[] = "12345";
	char str2[] = "+123";
	char str3[] = "-12345";
	char str4[] = "^%*&^&";
	char str5[] = "";
	char str6[] = "1234567890123456789";
	char str7[] = "-112565432664732648732";

	cout << StrToInt(str1) << '\t' << g_nStatus << endl;
	cout << StrToInt(str2) << '\t' << g_nStatus << endl;
	cout << StrToInt(str3) << '\t' << g_nStatus << endl;
	cout << StrToInt(str4) << '\t' << g_nStatus << endl;
	cout << StrToInt(str5) << '\t' << g_nStatus << endl;
	cout << StrToInt(str6) << '\t' << g_nStatus << endl;
	cout << StrToInt(str7) << '\t' << g_nStatus << endl;

	system("pause");
	return 0;
}
