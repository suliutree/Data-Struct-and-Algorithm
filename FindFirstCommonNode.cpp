/************************************************************************/
/* 两个链表的第一个公共结点                                            */
/************************************************************************/

#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

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

ListNode* FindFirstCommomNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;

	int length1 = 0;
	int length2 = 0;
	ListNode* pList1 = pHead1;
	while (pList1 != NULL)
	{
		length1++;
		pList1 = pList1->m_pNext;
	}
	ListNode* pList2 = pHead2;
	while (pList2 != NULL)
	{
		length2++;
		pList2 = pList2->m_pNext;
	}

	int diff;
	if (length1 >= length2)
	{
		pList1 = pHead1;
		pList2 = pHead2;
		diff = length1 - length2;
	}
	else
	{
		pList1 = pHead2;
		pList2 = pHead1;
		diff = length2 - length1;
	}

	for (int i = 0; i < diff; ++i)
		pList1 = pList1->m_pNext;

	bool found = false;
	while (pList1 != NULL && pList2 != NULL)
	{
		if (pList1 == pList2)
		{
			found = true;
			return pList1;
		}
		else
		{
			pList1 = pList1->m_pNext;
			pList2 = pList2->m_pNext;
		}
	}

	if (!found)
		return NULL;
}

int main()
{
	ListNode* list1 = NULL;
	ListNode* list2 = NULL;
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int array2[] = {1, 2, 3, 4, 5, 6};

	for (int i = 0; i < sizeof(array1)/sizeof(array1[0]); ++i)
	{
		AddToTail(&list1, array1[i]);
	}

	for (int i = 0; i < sizeof(array2)/sizeof(array2[0]); ++i)
	{
		AddToTail(&list2, array2[i]);
	}

	ListNode* commonNode = list1;
	for (int i = 0; i < 3; ++i)
		commonNode = commonNode->m_pNext;
	ListNode*pNode = list2;
	while (pNode->m_pNext != NULL)
		pNode = pNode->m_pNext;
	pNode->m_pNext = commonNode;

	pNode = FindFirstCommomNode(list1, list2);
	if (pNode != NULL)
		cout << pNode->m_nValue << endl;

	system("pause");
	return 0;
}
