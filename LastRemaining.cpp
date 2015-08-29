/************************************************************************/
/* 0，1，2，...，n-1这n个数围城一圈，每次删除第m个数，圆圈中最后剩下的数   */
/************************************************************************/

#include <iostream>
#include <list>

using namespace std;

int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	unsigned int i = 0;

	list<int> numbers;
	for (i = 0; i < n; ++i)
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}

		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		
		--current;
		numbers.erase(current);
		current = next;
	}
	return *current;
}

int main()
{
	unsigned int n = 10;
	unsigned int m = 3;
	int result = LastRemaining(n, m); //should be 3
	cout << result << endl;
	system("pause");
	return 0;
}
