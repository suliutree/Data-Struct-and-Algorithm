/************************************************************************/
/* 操作数：小写字母或者数字
/* 运算符：+,-,*,/,(,)
/* 例子：a+b*c+(d*e+f)*g	 ---------> abc*+de*f+g*+
/************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////
//中缀表达式转后缀表达式遵循以下原则：
//	1.遇到操作数，直接输出；
//	2.栈为空时，遇到运算符，入栈；
//	3.遇到左括号，将其入栈；
//	4.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出；
//	5.遇到其他运算符'+''-''*''/'时，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈；
//	6.最终将栈中的元素依次出栈，输出。
///////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>

using namespace std;

void InfixToSuffix(char* inputStr, int length)
{
	stack<char> s;
	for (int i = 0; i < length; ++i)
	{
		//(1)
		if ( (inputStr[i] >= '0' && inputStr[i] <= '9') || (inputStr[i] >= 'a' && inputStr[i] <= 'z') )
			cout << inputStr[i];

		if (s.empty())
		{
			//(2)
			if (inputStr[i] == '+' || inputStr[i] == '-' || inputStr[i] == '*' || inputStr[i] == '/' || inputStr[i] == '(')
				s.push(inputStr[i]);
		}
		else if (!s.empty())
		{
			//(3)
			if (inputStr[i] == '(')
				s.push(inputStr[i]);

			//(4)
			if (inputStr[i] == ')')
			{
				while (s.top() != '(')
				{
					cout << s.top();
					s.pop();
				}
				s.pop();
			}

			//(5)
			if (inputStr[i] == '+' || inputStr[i] == '-')
			{
				if (s.top() == '(')
					s.push(inputStr[i]);
				else
				{
					while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'))
					{
						cout << s.top();
						s.pop();
					}
					s.push(inputStr[i]);
				}
			}

			if (inputStr[i] == '*' || inputStr[i] == '/')
			{
				if (s.top() == '(' || s.top() == '+' || s.top() == '-')
					s.push(inputStr[i]);
				else
				{
					while (!s.empty() && (s.top() == '*' || s.top() == '/'))
					{
						cout << s.top();
						s.pop();
					}
					s.push(inputStr[i]);
				}
			}

		}

	}

	//(6)
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	char inputStr[100];
	cin >> inputStr;
	int length = strlen(inputStr);
	InfixToSuffix(inputStr, length);

	system("pause");
	return 0;
}
