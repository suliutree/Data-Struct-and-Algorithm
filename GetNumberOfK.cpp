/************************************************************************/
/* 数字在排序数组中出现的次数                                            */
/************************************************************************/

#include <iostream>

using namespace std;

int GetFirstK(int data[], int k, int begin, int end)
{
	if (begin > end)
		return -1;

	int mid = (begin + end) / 2;

	if (data[mid] == k)
	{
		if ( (mid > 0 && data[mid - 1] != k) || mid == 0 )
			return mid;
		else
			end = mid - 1;
	}
	else if (data[mid] > k)
		end = mid - 1;
	else
		begin  = mid + 1;

	return GetFirstK(data, k, begin, end);
}

int GetLastK(int data[], int k, int begin, int end)
{
	if (begin > end)
		return -1;

	int mid = (begin + end) / 2;

	if (data[mid] == k)
	{
		if ( (mid < end && data[mid + 1] != k) || mid == end )
			return mid;
		else
			begin = mid + 1;
	}
	else if (data[mid] > k)
		end = mid - 1;
	else
		begin  = mid + 1;

	return GetLastK(data, k, begin, end);
}

int GetNumberOfK(int data[], int length, int k)
{
	if (data == NULL)
		return -1;

	int begin = 0;
	int end = length - 1;
	
	int first = GetFirstK(data, k, begin, end);
	int last = GetLastK(data, k, begin, end);

	return last - first + 1;
}

int main()
{
	int data[] = {1, 2, 3, 3, 3, 3, 3, 4, 5, 6, 6};
	int length = sizeof(data)/sizeof(data[0]);
	int k = 3;

	int result = GetNumberOfK(data, length, k);

	cout << result << endl;
	system("pause");
}
