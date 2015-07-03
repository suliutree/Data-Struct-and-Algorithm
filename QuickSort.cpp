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

void QuickSort(int array[], int left, int right)
{
	if (left >= right)
		return;

	int index = partition(array, left, right);
	QuickSort(array, left, index - 1);
	QuickSort(array, index + 1, right);
}

int main()
{
	int array[] = { 23, 10, 24, 6, 7, 29, 15, 35, -9};
	int length = sizeof(array) / sizeof(array[0]);

	QuickSort(array, 0, length-1);

	for (int i = 0; i < length; ++i)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
