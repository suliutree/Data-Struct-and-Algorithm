/************************************************************************/
/* 寻找链表中环的入口结点                                                */
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


ListNode* FindLoop(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ListNode* slow = pHead;
	ListNode* fast = pHead;

	while (fast != NULL && fast->m_pNext != NULL)
	{
		slow = slow->m_pNext;
		fast = fast->m_pNext->m_pNext;
		if (fast == slow)
			break;
	}

	int circlLen = 1;
	while (fast->m_pNext != slow)
	{
		circlLen++;
		fast = fast->m_pNext;
	}

	slow = pHead;
	fast = pHead;

	for (int i = 0; i < circlLen; ++i)
		fast = fast->m_pNext;

	while (slow != fast)
	{
		slow = slow->m_pNext;
		fast = fast->m_pNext;
	}

	return slow;
}

int main()
{
	ListNode* list = NULL;
	int value[] = {23, 24, 14, 35, 9, 10, 29, 15, 1};
	for (int i = 0; i < sizeof(value) / sizeof(value[0]); ++i) 
	{
		AddToTail(&list, value[i]);
	}
	
	ListNode* pNode = list;
	for (int i = 0; i < 3; ++i)
		pNode = pNode->m_pNext;
	ListNode* pNodeTemp = pNode;

	while (pNode->m_pNext != NULL)
		pNode = pNode->m_pNext;
	pNode->m_pNext = pNodeTemp;

	pNode = FindLoop(list);
	cout << pNode->m_nValue << endl;

	system("pause");
	return 0;
}
