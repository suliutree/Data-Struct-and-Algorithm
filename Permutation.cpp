/************************************************************************/
/* 字符串的全排列（全排列就是从第一个字符起每个字符分别与它后面的字符交换） */
/************************************************************************/

#include <iostream>

using namespace std;

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
	if (pStr == NULL)
		return;

	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

int main()
{
	char str[] = "abcd";
	Permutation(str);

	system("pause");
	return 0;
}
