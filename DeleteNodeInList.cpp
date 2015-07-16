/************************************************************************/
/* 在O(1)的时间内删除单链表的结点（给定要删除的结点）                 */
/************************************************************************/

#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


void AddToTail(ListNode** pListHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pListHead == NULL)
	{
		*pListHead = pNew;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (pListHead == NULL || pToBeDeleted == NULL)
		return;

	// pToBedeleted不是尾结点
	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	// 链表只有一个结点，删除头结点（也是尾结点）
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	// 链表有多个结点，删除尾结点
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
			pNode = pNode->m_pNext;

		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
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

	ListNode* pToBeDeleted = list;
	DeleteNode(&list, pToBeDeleted);

	ListNode* pNode = list;
	while (pNode)
	{
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;

	ListNode* pToBeDeleted1 = list; 
	while (pToBeDeleted1->m_pNext != NULL)
		pToBeDeleted1 = pToBeDeleted1->m_pNext;
	DeleteNode(&list, pToBeDeleted1);

	pNode = list;
	while (pNode)
	{
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;


	system("pause");
	return 0;
}
