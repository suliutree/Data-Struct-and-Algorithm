/************************************************************************/
/* 数组中的逆序对                                                        */
/************************************************************************/

#include <iostream>

using namespace std;

int InversePairsCore(int* copy, int* data, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;

	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	// i初始化为前半段最后一个数字的下标
	int i = start + length;
	// j初始化为后半段最后一个数字的下标
	int j = end;
	int indexCopy = end;
	int count = 0;

	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
			copy[indexCopy--] = data[j--];
	}

	while (i >= start)
		copy[indexCopy--] = data[i--];
	while (j >= start + length + 1)
		copy[indexCopy--] = data[j--];

	// cout << left << ", " << right << ", " << count << endl;

	// left,right是分别统计的子数组内部的逆序对数目，count是统计的相邻子数组之间的逆序对数目
	return left + right + count;
}


int InversePairs(int* data, int length)
{
	if (data == NULL || length < 0)
		return 0;

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = data[i];

	// 不会破坏原始数组的顺序
	int count = InversePairsCore(copy, data, 0, length - 1);
	delete[] copy;

	return count;
}

int main()
{
	int array[] = { 7, 8, 6, 4, -2, 5};
	int length = sizeof(array) / sizeof(array[0]);

	int result = InversePairs(array, length);
	cout << result << endl;

	system("pause");
	return 0;
}
