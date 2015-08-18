//************************************************************************/
//* 大数相加，正负数相加均支					                         */
//************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

stack<int> s1;
stack<int> s2;
stack<int> s3;

void two_positive(const char* num1, const char* num2, char* result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	for (int i = 0; i < len1; ++i)
		s1.push(num1[i] - '0');

	for (int i = 0; i < len2; ++i)
		s2.push(num2[i] - '0');

	int tmp = 0;
	while (!s1.empty() && !s2.empty())
	{
		tmp += s1.top() + s2.top();
		s1.pop();
		s2.pop();
		s3.push(tmp % 10);
		tmp = tmp / 10;
	}

	while (!s1.empty())
	{
		tmp += s1.top();
		s1.pop();
		s3.push(tmp % 10);
		tmp = tmp / 10;
	}

	while (!s2.empty())
	{
		tmp += s2.top();
		s2.pop();
		s3.push(tmp % 10);
		tmp = tmp / 10;
	}

	if (tmp)
		s3.push(tmp);

	while (!s3.empty())
	{
		*result++ = s3.top() + '0';
		s3.pop();
	}
	*result = '\0';
}

void two_negative(const char* num1, const char* num2, char* result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	//注意第一位是符号'-'
	for (int i = 1; i < len1; ++i)
		s1.push(num1[i] - '0');

	for (int i = 1; i < len2; ++i)
		s2.push(num2[i] - '0');

	int tmp = 0;
	while (!s1.empty() && !s2.empty())
	{
		tmp += s1.top() + s2.top();
		s1.pop();
		s2.pop();
		s3.push(tmp % 10);
		tmp = tmp / 10;
	}

	while (!s1.empty())
	{
		tmp += s1.top();
		s1.pop();
		s3.push(tmp % 10);
		tmp = tmp / 10;
	}

	while (!s2.empty())
	{
		tmp += s2.top();
		s2.pop();
		s3.push(tmp % 10);
		tmp = tmp / 10;
	}

	if (tmp)
		s3.push(tmp);

	*result++ = '-';
	while (!s3.empty())
	{
		*result++ = s3.top() + '0';
		s3.pop();
	}
	*result = '\0';
}

int my_strcmp(const char* num1, const char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	if (len1 == len2)
		return strcmp(num1, num2);
	else if (len1 > len2)
		return 1;
	else
		return -1;
}


void sub(const char* num1, const char* num2, char* result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	for (int i = 0; i < len1; ++i)
		s1.push(num1[i] - '0');

	// 这里num2第一位是负号
	for (int i = 1; i < len2; ++i)
		s2.push(num2[i] - '0');

	int cmp = my_strcmp(num1, num2+1);

	// 两数除符号位外相等
	if (cmp == 0)
	{
		*result = '0';
		*result++ = '\0';
		return;
	}

	int tmp = 0;
	while (!s1.empty() && !s2.empty())
	{
		if (cmp > 0)
		{
			tmp += s1.top() - s2.top();
			s1.pop();
			s2.pop();
			if (tmp < 0) 
			{
				int prev = s1.top() - 1; //借位
				s1.pop();
				s1.push(prev);
				tmp += 10;
			}
			s3.push(tmp);
			tmp = tmp / 10;
		}
		else if (cmp < 0)
		{
			tmp += s2.top() - s1.top();
			s1.pop();
			s2.pop();
			if (tmp < 0) 
			{
				int prev = s2.top() - 1; //借位
				s2.pop();
				s2.push(prev);
				tmp += 10;
			}
			s3.push(tmp);
			tmp = tmp / 10;
		}
	}

	while (!s1.empty())
	{
		s3.push(s1.top());
		s1.pop();
	}

	while (!s2.empty())
	{
		s3.push(s2.top());
		s2.pop();
	}

	// 两数相减之后高位有可能为0，例如222和-221
	while (s3.top() == 0)
		s3.pop();
	
	if (cmp < 0)
		*result++ = '-';
	while (!s3.empty())
	{
		*result++ = s3.top() + '0';
		s3.pop();
	}
	*result = '\0';
}


void add (const char *num1, const char *num2, char *result)
{
	if ((num1[0] != '-' && num2[0] != '-'))
	{
		two_positive(num1, num2, result);
	}
	else if (num1[0] == '-' && num2[0] == '-')
	{
		two_negative(num1, num2, result);
	}
	else if (num1[0] == '-' && num2[0] != '-')
	{
		sub(num2, num1, result);
	}
	else if (num1[0] != '-' && num2[0] == '-')
	{
		sub(num1, num2, result);
	}
}

int main(void)
{
	char num1[100];
	char num2[100];
	char result[100];
	printf("input num1: ");
	cin>>num1;
	printf("input num2: ");
	cin>>num2;
	
	add(num1, num2, result);
	cout << result << endl;

	system("pause");
	return 0;
}
