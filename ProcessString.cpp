#include <stdio.h>
#include <assert.h>
#include <conio.h>

// 返回str的长度，不包括字符串结束符null
int my_strlen(const char *str)
{
	assert(str != NULL);
	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

/**
比较字符串s1与s2是否相同
函数中进行强制转换（unsigned char*）的原因如下：
无符号数的减法运算能保证只要数字每位一样，那么相减必定为0，反之也成立。
有符号数无法保证这一点，当相减为0时，两数的每一位不一定相等。
例如：
signed char a = 0;
signed char b = -128;
signed char c = a - b;
运行结果c为0，但很显然，a、b并不相等。
标准并未规定char是signed的还是unsigned的，所以要判断两个变量是否每个bit都相等，必须转换为无符号整数。
*/
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;
	while ( !(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
	{ 
		str1++;
		str2++;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	
	return ret;
}

// 把src所指字符串添加到dest结尾处（覆盖dest结尾处的'\0'）并添加'\0'
// dest必须具有足够大的空间存放新生成的字符串
char* my_strcat(char* strDest, const char* strSrc)
{
	assert(strDest != NULL && strSrc != NULL);
	char* address = strDest;
	while (*strDest)
		strDest++;
	
	while (*strDest++ = *strSrc++);
	return address;
}

// 把从src地址开始且含有null结束符的字符串复制到以dest开始的地址空间
// dest必须具有足够大的空间存放新生成的字符串
char* my_strcpy(char* strDest, char* strSrc)
{
	assert(strDest != NULL && strSrc != NULL);
	char* address = strDest;
	while ((*strDest++ = *strSrc++) != '\0');
	return address;
}

/*
strcpy提供了字符串的复制。即strcpy只用于字符串复制，并且它不仅复制字符串内容之外，还会复制字符串的结束符。
memcpy提供了一般内存的复制。即memcpy对于需要复制的内容没有限制，因此用途更广。
*/


// 从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
// 函数返回dest的指针
void* my_memcpy(void* dest, const void* src, size_t n)
{
	assert(dest != NULL && src != NULL);
	char* tmp = (char*)dest; // 注意这里需要显示转换
	const char* s = (char*)src;
	for (size_t i = 0; i < n; ++i)
	{
		tmp[i] = s[i];
	}
	return dest;
}

// 将ptr中前n个字节用value替换并返回ptr
// 作用是在一段内存块中填充某个给定的值，它是对较大结构体或数组进行
void* my_memset(void* ptr, int value, size_t n)
{
	char* xs = (char*)ptr;
	while (n--)
		*xs++ = value;
	return ptr;
}


int main()
{
	char str[] = "abcde";
	int len = my_strlen(str);
	printf("%d\n", len);

	char str1[] = "abcdef1";
	char str2[] = "abcdef";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);

	char dest[10] = "abc";
	char src[] = "def";
	char* catRet = my_strcat(dest, src);
	printf("%s\n", catRet);

	char dest1[] = "abcdef";
	char src1[] = "tree";
	char* cpyRet = my_strcpy(dest1, src1);
	printf("%s\n", cpyRet);

	char memcpyRet[20];
	my_memcpy(memcpyRet, src, (my_strlen(src) + 1));
	printf("%s\n", memcpyRet);
	my_memcpy(memcpyRet, src1, 2);
	printf("%s\n", memcpyRet);

	char arr[10];
	my_memset(arr, 0, sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	getch();
	return 0;
}
