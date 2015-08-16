/************************************************************************/
/* 字符串过滤程序，若字符串中出现多个相同的字符，将非首次出现的字符过滤掉   */
/************************************************************************/

#include <iostream>

using namespace std;

void stringFilter(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	if (pInputStr == NULL)
		return;

	const int tableSize = 26;
	bool hashTable[tableSize] = {0};

	int j = 0;
	for (int i = 0; i < lInputLen; ++i)
	{
		if (hashTable[pInputStr[i] - 'a'])
		{
			continue;
		}
		else
		{
			hashTable[pInputStr[i] - 'a'] = true;
			pOutputStr[j++] = pInputStr[i];
		}
	}
	pOutputStr[j] = '\0';
}

int main()
{
	const char inStr1[] = "pppppp";
	const char inStr2[] = "abaabbccdee";
	const int length1 = sizeof(inStr1)/sizeof(inStr1[0]);
	char outStr1[26] = {0};
	const int length2 = sizeof(inStr2)/sizeof(inStr2[0]);
	char outStr2[26] = {0};

	stringFilter(inStr1, length1, outStr1); 
	stringFilter(inStr2, length2, outStr2); 

	cout << outStr1 << endl;
	cout << outStr2 << endl; 
	system("pause");
	return 0;
}
