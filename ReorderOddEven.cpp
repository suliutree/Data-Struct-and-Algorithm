/************************************************************************/
/* 调整数组顺序，使奇数位于偶数前面                                       */
/************************************************************************/

#include <iostream>

using namespace std;

void Reorder(int pData[], int length, bool (*func)(int))
{
	if (pData == NULL || length <= 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		while (pBegin < pEnd && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEven(int* pData, int length)
{
	Reorder(pData, length, isEven);
}

int main()
{
	int array[] = { -1, 2, 3, -4, 5, 6, 7, 8, 9};
	int length = sizeof(array) / sizeof(array[0]);
	ReorderOddEven(array, length);

	for (int i = 0; i < length; ++i)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
