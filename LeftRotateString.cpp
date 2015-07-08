/************************************************************************/
/* 左旋字符串，如"abcdef"，输入2，则左旋字符串为"cdefab"                  */
/************************************************************************/

#include <iostream>

using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* LeftRotateString(char* pStr, int n)
{
	if (pStr != NULL)
	{
		int nLength = strlen(pStr);
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			// 翻转字符串的前n个字符
			Reverse(pFirstStart, pFirstEnd);
			// 翻转字符串后面的字符
			Reverse(pSecondStart, pSecondEnd);
			// pFirstStart和pSecondEnd指向字符串的位置并未改变，只是指向的内容变化了
			Reverse(pFirstStart, pSecondEnd);
		}
	}
	return pStr;
}

int main()
{
	char std[] = "hello world!";
	int n = 3;
	char* pRet = LeftRotateString(std, n);
	cout << pRet << endl;

	system("pause");
	return 0;
}
