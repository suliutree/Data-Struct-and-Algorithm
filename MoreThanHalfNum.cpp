#include <iostream>

using namespace std;

bool g_bInputInvalid = false;

int Partition(int array[], int left, int right)
{
	int pivot = array[right];

	while (left != right)
	{
		while (array[left] < pivot && left < right)
			++left;
		if (left < right)
			swap(array[left], array[right--]);

		while (array[right] > pivot && left < right)
			--right;
		if (left < right)
			swap(array[left++], array[right]);
	}

	return left;

}

bool CheckMoreThanHalf(int array[], int length, int result)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == result)
			times++;
	}

	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		return false;
	}
	else
		return true;
}


int MoreThanHalfNum1(int array[], int length)
{
	if (array == NULL || length <= 0)
	{
		g_bInputInvalid = true;
		return 0;
	}

	int mid = length >> 1;
	int left = 0;
	int right = length - 1;
	int index = Partition(array, left, right);

	while (index != mid)
	{
		if (index < mid)
		{
			left = index+1;
			index = Partition(array, left, right);
		}
		else if (index > mid)
		{
			right = index-1;
			index = Partition(array, left, right);
		}
	}

	int result = array[mid];

	if (!CheckMoreThanHalf(array, length, result))
		return 0;

	return result;
}


int MoreThanHalfNum2(int array[], int length)
{

	if (array == NULL || length <= 0)
	{
		g_bInputInvalid = true;
		return 0;
	}

	int result = array[0];
	int time = 1;

	for (int i = 1; i < length; ++i)
	{
		if (time == 0)
		{
			result  = array[i];
			time = 1;
		}
		else if (array[i] == result)
		{
			time++;
		}
		else
		{
			time--;
		}
	}
	
	if (!CheckMoreThanHalf(array, length, result))
		return 0;

	return result;
}


int main()
{
	int array[] = {1, 2, 4, 4, 4, 5, 4, 2, 2, 2, 2, 2, 2};
	int length = sizeof(array) / sizeof(array[0]);

	int ret1 = MoreThanHalfNum2(array, length);
	cout << ret1 << endl;
	cout << (g_bInputInvalid == true ? "InputInvalid" : "InputValid") << endl;

	int ret2 = MoreThanHalfNum1(array, length);
	cout << ret2 << endl;
	cout << (g_bInputInvalid == true ? "InputInvalid" : "InputValid") << endl;

	system("pause");
	return 0;
}
