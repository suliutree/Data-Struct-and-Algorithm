/************************************************************************/
/* 返回链表中间结点                                                     */
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

ListNode* MidPoint(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ListNode* chaser = pHead, *runner = pHead;

	// runner->m_pNext != NULL这个判断条件防止越界
	while (runner->m_pNext != NULL && runner->m_pNext->m_pNext != NULL)
	{
		chaser = chaser->m_pNext;
		runner = runner->m_pNext->m_pNext;
	}
	return chaser;
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
	int value[] = {23, 24, 14, 35, 9, 10, 29, 15, 1};
	for (int i = 0; i < sizeof(value) / sizeof(value[0]); ++i) 
	{
		AddToTail(&list, value[i]);
	}
	
	cout << "PrintList:" << endl;
	PrintList(list);
	cout << endl;

	ListNode* ret = MidPoint(list);
	cout << ret->m_nValue << endl;

	system("pause");
	return 0;
}
