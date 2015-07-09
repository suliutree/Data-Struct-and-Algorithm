/************************************************************************/
/* 判断一个字符串中每个字符是不是唯一的                                  */
/************************************************************************/

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool IsUnique(string input)
{
	bitset<256> hashMap;
	for (int i = 0; i < input.length(); ++i)
	{
		if (hashMap[(int)input[i]])
			return false;
		hashMap[(int)input[i]] = 1;
	}
	return true;
}

int main()
{
	string input;
	cout << "Input string: ";
	cin >> input;

	cout << IsUnique(input) << endl;
	system("pause");
	return 0;
}
