/************************************************************************/
/* 利用两个栈实现一种特定的输出顺序                                       */
/************************************************************************/


#include <iostream>
#include <stack>

using namespace std;

stack<int> SortStack(stack<int> &input)
{
	stack<int> output;

	while (!input.empty())
	{
		int value = input.top();
		input.pop();

		while (!output.empty() && output.top() < value)
		{
			input.push(output.top());
			output.pop();
		}

		output.push(value);
	}
	return output;
}

int main()
{
	stack<int> inputStack;
	int num;
	while (cin >> num)
		inputStack.push(num);

	stack<int> outputStack = SortStack(inputStack);

	while (!outputStack.empty())
	{
		cout << outputStack.top() << endl;
		outputStack.pop();
	}

	system("pause");
	return 0;
}
