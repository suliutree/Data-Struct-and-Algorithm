#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
	void enqueue(int value);
	int dequeue();
	bool isEmpty();

private:
	stack<int> inputStack;
	stack<int> outputStack;
};

void MyQueue::enqueue(int value)
{
	inputStack.push(value);
}

int MyQueue::dequeue()
{
	int value;

	if (!outputStack.empty())
	{
		value = outputStack.top();
		outputStack.pop();
		return value;
	}

	while (!inputStack.empty())
	{
		outputStack.push(inputStack.top());
		inputStack.pop();
	}

	value = outputStack.top();
	outputStack.pop();
	return value;
}

bool MyQueue::isEmpty()
{
	return inputStack.empty() && outputStack.empty(); 
}

int main()
{
	MyQueue* mq = new MyQueue();
	int num;
	while (cin >> num)
	{
		mq->enqueue(num);
	}

	cout << mq->dequeue() << endl;

	mq->enqueue(-1);

	while (!mq->isEmpty())
		cout << mq->dequeue() << endl;

	system("pause");
	return 0;
}
