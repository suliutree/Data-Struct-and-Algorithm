/************************************************************************/
/* 每次从0-n-1的圆圈中删除第m个数字，最后一个剩下的数字                   */
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
	 cout << LastRemaining(10, 3) << endl;

	 system("pause");
	 return 0;
}
