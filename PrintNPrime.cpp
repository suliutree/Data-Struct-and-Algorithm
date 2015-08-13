/************************************************************************/
/* 写函数，输出前N个素数。不需要考虑整数溢出问题，也不需要使用大数处理算法 */
/************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

bool IsPrime(unsigned int n)
{
	if (n < 2)
		return false;

	int k = (int)sqrt((double)n);
	for (unsigned int i = 2; i <= k; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void PrintNPrime(int N)
{
	int count = 0;
	int num = 2;
	while (count < N)
	{
		if (IsPrime(num))
		{
			cout << num << endl;
			count++;
		}
		num++;
	}
}

int main()
{
	int N;
	cin >> N;
	PrintNPrime(N);

	system("pause");
	return 0;
}
