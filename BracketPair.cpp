#include <iostream>
#include <stack>

using namespace std;

bool BracketPair(char* pStr)
{
	if (pStr == NULL)
		return true;

	stack<char> myStack;

	for (int i = 0; i < strlen(pStr); ++i)
	{
		if (myStack.empty() || pStr[i] == '{' || pStr[i] == '[' || pStr[i] == '(')
			myStack.push(pStr[i]);

		switch(pStr[i])
		{
		case '}':
			if (myStack.top() == '{')
				myStack.pop();
			break;
		case ']':
			if (myStack.top() == '[')
				myStack.pop();
			break;
		case ')':
			if (myStack.top() == '(')
				myStack.pop();
			break;
		}
	}

	if (myStack.empty())
		return true;
	else
		return false;
}

int main()
{
	char str[] = "[{[]}]{}{}{()}";
	cout << BracketPair(str) << endl;

	system("pause");
	return 0;
}
