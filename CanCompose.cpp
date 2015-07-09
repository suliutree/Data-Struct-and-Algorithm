/************************************************************************/
/* 判断字符串newspaper中出现的字符是否能够组成message                    */
/************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool CanCompose(string newspaper, string message)
{
	unordered_map<char, int> hashMap;

	if (newspaper.length() < message.length())
		return false;

	for (int i = 0; i < newspaper.length(); ++i)
		hashMap[newspaper[i]]++;

	for (int i = 0; i < message.length(); ++i)
	{
		//if (hashMap[message[i]])
		//	hashMap[message[i]]--;
		//else
		//	return false;

		if (hashMap.count(message[i]) == 0)
			return false;

		if (--hashMap[message[i]] < 0)
			return false;
	}

	return true;
}

int main()
{
	string newspaper;
	cout << "Input newspaper： ";
	cin >> newspaper;

	string message;
	cout << "Input message: ";
	cin >> message;

	cout << CanCompose(newspaper, message) << endl;

	system("pause");
	return 0;
}
