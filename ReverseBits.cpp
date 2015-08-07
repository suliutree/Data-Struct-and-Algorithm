/************************************************************************/
/* 对一个32位的无符号整数（unsigned int）进行反转二进制                   */
/*  input：43261596   (00000010 10010100 00011110 10011100)				*/
/*  output：964176192 (00111001 01111000 00101001 01000000)				*/
/************************************************************************/

#include <iostream>
#include <assert.h>

using namespace std;

unsigned int ReverseBits(unsigned int num)
{
	unsigned int count = sizeof(num) * 8 - 1;
	unsigned int reverse_num = num;
	num >>= 1;
	while (num)
	{
		reverse_num <<= 1;
		reverse_num |= num&1;
		num >>= 1;
		count--;
	}
	reverse_num <<= count;
	return reverse_num;
}


int main()
{
	cout << ReverseBits(43261596) << endl; // output:964176192

	system("pause");
	return 0;
}
