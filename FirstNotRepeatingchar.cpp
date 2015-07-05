#include <iostream>

using namespace std;

char FirstNotRepeatingChar(char* pStr)
{
	if (pStr == NULL)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;

	char* pHashKey = pStr;
	while (*pHashKey != '\0')
	{
		hashTable[*pHashKey]++;
		pHashKey++;
	}

	pHashKey = pStr;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}

	return '\0';
}

int main()
{
	char* pStr1 = "abcdaabcgh";
	char result = FirstNotRepeatingChar(pStr1);
	cout << result << endl;

	char* pStr2 = "abcdabcd";
	result = FirstNotRepeatingChar(pStr2);
	cout << result << endl;

	char* pStr3 = "";
	result = FirstNotRepeatingChar(pStr3);
	cout << result << endl;

	system("pause");
	return 0;
}
