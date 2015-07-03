/************************************************************************/
/* 快速选择算法：在O(n)的时间内从一个无序数组中返回第K大的元素             */
/************************************************************************/

#include <iostream>

using namespace std;

int partition(int array[], int left, int right)
{
	int pivot = array[right];

	while (left != right)
	{
		while (array[left] <= pivot && left < right)
			left++;
		if (left < right)
			swap(array[left], array[right--]);

		while (array[right] >= pivot && left < right)
			right--;
		if (left < right)
			swap(array[left++], array[right]);
	}

	return left;
}

// k从1开始算起
int QuickSelect(int array[], int left, int right, int k)
{
	if (left >= right)
		return array[left];

	int index = partition(array, left, right);
	int size = index - left + 1;
	if (size == k)
		return array[left + k - 1];
	else if (size > k)
		return QuickSelect(array, left, index-1, k);
	else if (size < k)
		return QuickSelect(array, index+1, right, k-size);
}


int main()
{
	int array[] = { 23, 10, 24, 6, 7, 29, 15, 35, -9};
	int length = sizeof(array) / sizeof(array[0]);

	int k1 = 1;
	int k2 = 4;
	int k3 = length;
	cout << QuickSelect(array, 0, length-1, k1) << endl;
	cout << QuickSelect(array, 0, length-1, k2) << endl;
	cout << QuickSelect(array, 0, length-1, k3) << endl;

	system("pause");
	return 0;
}
