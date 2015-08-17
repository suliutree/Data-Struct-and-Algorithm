/************************************************************************/
/* 大数相加，目前只支持两个数同为正数或同为负数                         */
/************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

stack<int>s1;
stack<int>s2;
stack<int>s3;

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
