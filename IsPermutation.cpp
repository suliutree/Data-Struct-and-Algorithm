/************************************************************************/
/* 判断两个字符串是不是同一个字符串的不同排列                            */
/************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool IsPermutation(string stringA, string stringB)
{
	if (stringA.length() != stringB.length())
		return false;

	unordered_map<char, int> hashMapA;
	unordered_map<char, int> hashMapB;
	for (int i = 0; i < stringA.length(); ++i)
	{
		hashMapA[stringA[i]]++;
		hashMapB[stringB[i]]++;
	}

	if (hashMapA.size() != hashMapB.size())
		return false;

	unordered_map<char, int>::iterator it;
	for (it = hashMapA.begin(); it != hashMapA.end(); it++)
	{
		if (it->second != hashMapB[it->first])
			return false;
	}

	return true;
}

int main()
{
	string stringA;
	cout << "Input stringA: ";
	cin >> stringA;

	string stringB;
	cout << "Input stringB: ";
	cin >> stringB;

	cout << IsPermutation(stringA, stringB) << endl;

	system("pause");
	return 0;
}
