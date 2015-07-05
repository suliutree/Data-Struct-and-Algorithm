#include <iostream>

using namespace std;

bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int r = 0;
		int c = columns - 1;
		while (r < rows && c >= 0)
		{
			if (matrix[r * columns + c] == number)
			{
				found = true;
				break;
			}
			else if (matrix[r * columns + c] > number)
				c--;
			else 
				r++;
		}
	}
	return found;
}

int main()
{
	int array[][4] = {
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15}
	};

	cout << "发现中间值(true)： ";
	bool result1 = Find((int*)array, 4, 4, 7);
	cout << result1 << endl;

	cout << "未发现(false)： ";
	bool result2 = Find((int*)array, 4, 4, 23);
	cout << result2 << endl;

	cout << "发现最大值(true)： ";
	bool result3 = Find((int*)array, 4, 4, 15);
	cout << result3 << endl;

	cout << "发现最小值(true)： ";
	bool result4 = Find((int*)array, 4, 4, 1);
	cout << result4 << endl;

	
	system("pause");
	return 0;
}
