/************************************************************************/
/* 连续子数组的最大和                                                    */
/************************************************************************/

#include <iostream>

using namespace std;

// 全局变量，当返回的子数组的和为0的时候，判断是最大值为0还是无效输入
bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int pData[], int length)
{
	if (pData == NULL || length <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreastSum = 0;

	for (int i = 0; i < length; ++i)
	{
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else		
			nCurSum += pData[i];

		if (nCurSum > nGreastSum)
			nGreastSum = nCurSum;
	}
	return nGreastSum;
}

int main()
{
	int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = sizeof(array) / sizeof(array[0]);

	int result = FindGreatestSumOfSubArray(array, length);
	cout << result << endl;

	system("pause");
	return 0;
}
