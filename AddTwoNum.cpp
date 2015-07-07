/************************************************************************/
/* 不用加减乘除运算符号，求两个整数的和                                  */
/************************************************************************/

#include <iostream>

using namespace std;

int AddTwoNum(int num1, int num2)
{
	int sum = 0;
	int carry = 0;

	do 
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return sum;
}

int main()
{
	int num1, num2;
	cout << "Input num1: ";
	cin >> num1;
	cout << "Input num2: ";
	cin >> num2;

	cout << AddTwoNum(num1, num2) << endl;

	system("pause");
	return 0;
}
