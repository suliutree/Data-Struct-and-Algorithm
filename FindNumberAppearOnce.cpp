/************************************************************************/
/* 一个整形数组中除了两个数字外，其他的数字都出现了两次，找出这两个数字   */
/************************************************************************/

#include <iostream>

using namespace std;

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	// indexBit的值不能超过计算机所能表示的整数的位数
	while ( ((num & 1) == 0) && (indexBit < sizeof(int)*8))
	{
		indexBit++;
		num = num >> 1;
	}

	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumberAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == NULL || length < 2)
		return;

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;
	for (int i = 0; i < length; ++i)
	{
		if (IsBit1(data[i], indexOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}

int main()
{
	int data[] = {1, 2, 5, 7, 6, 2, 1, 6};
	int length = sizeof (data) / sizeof (data[0]);

	int num1, num2;
	FindNumberAppearOnce(data, length, &num1, &num2);
	cout << num1 << '\t' << num2 << endl;

	system("pause");
	return 0;
}
