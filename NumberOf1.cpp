#include <iostream>

using namespace std;

// 循环的次数等于整数二进制的位数
int FirstNumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;

		flag = flag << 1;
	}

	return count;
}

// 整数中有几个1就循环几次
int SecondNumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int num;
	cout << "Input number: ";
	cin >> num;
	int result1 = FirstNumberOf1(num);
	cout << result1 << endl;
	int result2 = SecondNumberOf1(num);
	cout << result2 << endl;

	system("pause");
	return 0;
}
