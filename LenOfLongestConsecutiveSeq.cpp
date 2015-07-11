/************************************************************************/
/* 得到数组中最长连续序列的长度，如[12, 2, 5, 3, 9, 4, 14, 1]，最长连续
序列为[1, 2, 3, 3, 4, 5]，则返回长度5									*/
/************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Bound
{
	int high;
	int low;

	Bound(int h = 0, int l = 0)
	{
		high = h;
		low = l;
	}
};

int LengthOfLongestConsecutiveSequence(vector<int>& num)
{
	unordered_map<int, Bound> table;

	int local;
	int maxLen = 0;

	for (int i = 0; i < num.size(); i++)
	{
		if (table.count(num[i]))
			continue;

		local = num[i];

		int low = local, high = local;

		if (table.count(local - 1))
			low = table[local - 1].low;

		if (table.count(local + 1))
			high = table[local + 1].high;

		table[low].high = table[local].high = high;
		table[high].low = table[local].low = low;

		if (high - low + 1 > maxLen)
			maxLen = high - low + 1;
	}
	return maxLen;
}

int main()
{
	int array[] = {12, 2, 5, 3, 9, 4, 14, 1};
	int length = sizeof(array)/sizeof(array[0]);
	vector<int> num(length);
	for (int i = 0; i < length; ++i)
		num[i] = array[i];

	int ret = LengthOfLongestConsecutiveSequence(num);
	cout << ret << endl;

	system("pause");
	return 0;
}
