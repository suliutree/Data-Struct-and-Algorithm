#include <iostream>

using namespace std;

void merge_sort(int array[], int helper[], int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	merge_sort(array, helper, left, mid);
	merge_sort(array, helper, mid + 1, right);

	int helperLeft = left;
	int helperRight = mid+1;
	int curr = left;
	for (int i = 0; i <= right; ++i)
		helper[i] = array[i];

	while (helperLeft <= mid && helperRight <= right)
	{
		if (helper[helperLeft] <= helper[helperRight])
			array[curr++] = helper[helperLeft++];
		else
			array[curr++] = helper[helperRight++];
	}

	while (helperLeft <= mid)
		array[curr++] = helper[helperLeft++];
}

int main()
{
	int array[] = { 23, 10, 24, 6, 7, 29, 15, 35, -9};
	const int length = sizeof(array) / sizeof(array[0]);
	int helper[length];

	merge_sort(array, helper, 0, length-1);

	for (int i = 0; i < length; ++i)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
