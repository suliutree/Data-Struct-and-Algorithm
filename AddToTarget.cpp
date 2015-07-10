/************************************************************************/
/* 找出数组中的两个数（唯一一对），加起来等于给定的数，返回两个数的下标 */
/************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> AddsToTarget(vector<int> &numbers, int target)
{
	unordered_map<int, int> numToIndex;
	vector<int> vi(2);

	vector<int>::iterator it = numbers.begin();
	for ( ; it != numbers.end(); ++it)
	{
		if (numToIndex.count(target - *it))
		{
			vi[0] = numToIndex[target - *it] + 1;
			vi[1] = (int)(it - numbers.begin()) + 1;
			return vi;
		}
		numToIndex[*it] = (int)(it - numbers.begin());
	}
}

int main()
{
	int array[] = {12, 23, 45, 61, 3, 7, 9, 49};
	int length = sizeof(array)/sizeof(array[0]);
	vector<int> vec(length);
	for (int i = 0; i < length; ++i)
		vec[i] = array[i];

	vector<int> ret = AddsToTarget(vec, 32);

	cout << ret[0] << endl;
	cout << ret[1] << endl;

	system("pause");
	return 0;
}
