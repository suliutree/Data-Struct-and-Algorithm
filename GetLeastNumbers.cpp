/************************************************************************/
/* 最小的k个数                                                          */
/************************************************************************/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

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

void GetLeastNumbers(int array[], int length, int output[], int k)
{
	if (array == NULL || output == NULL || k > length || length <= 0 || k <= 0)
		return;

	int left = 0;
	int right = length - 1;

	int index = Partition(array, left, right);

	while (index != k-1)
	{
		if (index < k-1)
		{
			left = index + 1;
			index = Partition(array, left, right);
		}
		else if (index > k-1)
		{
			right = index - 1;
			index = Partition(array, left, right);
		}
	}

	for (int i = 0; i < k; ++i)
		output[i] = array[i];
}


// 适合处理海量数据的方法
typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();

	if (k <= 0 || data.size() < k)
		return;

	for (vector<int>::const_iterator it = data.begin(); it != data.end(); ++it)
	{
		if (leastNumbers.size() < k)
			leastNumbers.insert(*it);
		else
		{
			setIterator iterGreatest = leastNumbers.begin();

			if (*it < *(leastNumbers.begin()))
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*it);
			}
		}
	}
}



int main()
{
	int array[] = {6, 7, 48, 3, 7, 45, 8, 37, 5};
	int length = sizeof(array) / sizeof(array[0]);
	const int k = 8;
	int output[k];

	GetLeastNumbers(array, length, output, k);

	for (int i = 0; i < k; ++i)
		cout << output[i] << " ";
	cout << endl;

//**************************************************
	vector<int> vec(length);
	for (int i = 0; i < length; ++i)
		vec[i] = array[i];
	vector<int> leastNumbersVec(k);
	vector<int>::iterator itBegin = leastNumbersVec.begin();
	vector<int>::iterator itEnd = leastNumbersVec.end();
	intSet leastNumbers(itBegin, itEnd);

	GetLeastNumbers(vec, leastNumbers, k);
	for (setIterator it = leastNumbers.begin(); it != leastNumbers.end(); ++it)
		cout << *it << " ";
	cout << endl;
//***************************************************
	system("pause");
	return 0;
}
