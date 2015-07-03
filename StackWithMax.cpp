#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

class StackWithMax
{
public:
	void myPush(int);
	void myPop();
	int getTop();
	int getMax();
	bool isEmpty();

private:
	stack<int> valueStack;
	stack<int> maxStack;
};

void StackWithMax::myPush(int value)
{
	if (maxStack.empty() || maxStack.top() < value)
		maxStack.push(value);
	else
		maxStack.push(maxStack.top());

	valueStack.push(value);
}

void StackWithMax::myPop()
{
	assert(valueStack.size() > 0 && maxStack.size() > 0);

	valueStack.pop();
	maxStack.pop();
}

int StackWithMax::getTop()
{
	assert(valueStack.size() > 0 && maxStack.size() > 0);

	return valueStack.top();
}

int StackWithMax::getMax()
{
	assert(valueStack.size() > 0 && maxStack.size() > 0);

	return maxStack.top();
}

bool StackWithMax::isEmpty()
{
	return valueStack.empty() && maxStack.empty();
}

int main()
{
	StackWithMax* swm = new StackWithMax();
	int num;
	while (cin >> num)
	{
		swm->myPush(num);
	}

	while (!swm->isEmpty())
	{
		cout << swm->getTop() << "\t" << swm->getMax() << endl;
		swm->myPop();
	}

	system("pause");
	return 0;
}
