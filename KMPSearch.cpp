#include <iostream>
#include <stdio.h>

using namespace std;

int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0;
	int j = 0;

	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;

}

/*
原始串：BBC ABCDAB ABCDABCDABDE
匹配串：ABCDABD

 A B C D A B D
-1 0 0 0 0 1 2

BBC ABCDAB ABCDABCDABDE
    ABCDABD
当字符串匹配到这里时 i = 10，j = 6，此时 j!=-1 而且当前字符不匹配
执行 j = next[j]，j则为2，在执行下一步时会比较 s[10] 与 p[2]，如下：
BBC ABCDAB ABCDABCDABDE
        ABCDABD

s[10]与p[2]不匹配，执行 j = next[j]，j则为0，下一步比较 s[10] 与 p[0]，如下：
BBC ABCDAB ABCDABCDABDE
          ABCDABD
以此类推

*/

int KMPSearch(char* s, char* p, int next[])
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0;
	int j = 0;

	while (i < sLen && j < pLen)
	{
		// 如果 j == -1（表示重新从子串的第一位开始比较） 或者当前字符匹配成功
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == pLen)
		return i - j;
	else
		return -1;
}


/*

      		A		B		C		D		A		B		D
	k   	-1		0		-1,0		-1,0		-1,0		1		2
	j	  0		1		2		3		4		5		6
 	next	-1		0		0		0		0		1		2

*/

void GetNext(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;

	while (j < pLen - 1)
	{
		// p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int main()
{
	char s[] = "abcdefdefdefghij";
	char p[] = "efdef";
	const int pLen = sizeof(p)/sizeof(p[0]) - 1;
	int next[pLen];

	int result1 = ViolentMatch(s, p);
	cout << result1 << endl;

	GetNext(p, next);
	int result2 = KMPSearch(s, p, next);
	cout << result2 << endl;

	system("pause");
	return 0;
}
