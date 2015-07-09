/************************************************************************/
/* 链表中倒数第K个结点                                                 */
/************************************************************************/

#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/*
	这里参数pHead是一个指向指针的指针。当我们往一个空链表中插入一个结点时，
	新插入的结点就是链表的头指针。由于此时会改动头指针，因此必须把pHead参数
	设为指向指针的指针，否则出了这个函数pHead仍然是一个空指针（因为这个新插
	入的结点是在函数中定义的）。
*/
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}


ListNode* FindKthToTail(ListNode* pListHead, int k)
{
	if (pListHead == NULL || k <= 0)
		return NULL;

	int length = 0;
	ListNode* pNode = pListHead;
	while (pNode != NULL)
	{
		length++;
		pNode = pNode->m_pNext;
	}

	if (length < k)
		return NULL;

	ListNode* pFirst = pListHead;
	ListNode* pSecond = pListHead;
	for (int i = 0; i < k; ++i)
		pFirst = pFirst->m_pNext;

	while (pFirst != NULL)
	{
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}

	return pSecond;
}


void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
}


int main()
{
	ListNode* list = NULL;
	int value[] = {23, 24, 14, 35, 9, 10, 29, 15};
	for (int i = 0; i < sizeof(value) / sizeof(value[0]); ++i) 
	{
		AddToTail(&list, value[i]);
	}
	
	cout << "PrintList:" << endl;
	PrintList(list);
	cout << endl;

	int k = 3;
	ListNode* ret = FindKthToTail(list, k);
	if (ret != NULL) 
	{
		cout << ret->m_nValue << endl;
	}
	else
	{
		cout << "Input Invalid!" << endl;
	}

	system("pause");
	return 0;
}
