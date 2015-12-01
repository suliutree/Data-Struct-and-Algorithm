#include <iostream>

using namespace std;

void AdjustDown(int A[], int k, int len);

// A[0]中不存储元素，实际存储从A[1]开始
void BuildMaxHeap(int A[], int len)
{
	for (int i = len/2; i > 0; i--)	// 从i=[len/2]~1，反复调整堆
		AdjustDown(A, i, len);
}

// 将元素k向下进行调整
void AdjustDown(int A[], int k, int len)
{
	A[0] = A[k];							// A[0]暂存
	for (int i = 2*k; i <= len; i *= 2)
	{
		if (i < len && A[i] < A[i+1])
			i++;
		if (A[0] >= A[i])
			break;
		else
		{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];
}

void HeapSort(int A[], int len)
{
	BuildMaxHeap(A, len);			// 初始建堆
	for (int i = len; i > 1; --i)	// n-1趟建堆和交换过程
	{								
		swap(A[i], A[1]);			// 输出堆顶元素（和堆底元素交换）
		AdjustDown(A, 1, i-1);		// 整理，把剩余的i-1个元素整理成堆
	}
}

int main()
{
	int A[] = { NULL, 12, 34, 67, 54, 32, 41, 90, 98, 78};
	int len = sizeof(A)/sizeof(int)-1;

	cout << len << endl;

	HeapSort(A, len);
	for (int i = 1; i <= len; ++i)
		cout << A[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
