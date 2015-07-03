#include <iostream>
#include <stack>

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

void RemoveNode(ListNode** pHead, int value)
{
	// pHead == NULL表示链表为一个空链表
	// *pHead == NULL表示指向链表的指针为一个空指针
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
				pNode = pNode->m_pNext;

		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
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

void PrintListReverseIterative(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		cout << nodes.top()->m_nValue << " ";
		nodes.pop();
	}
}

void PrintListReverseRecursive(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
			PrintListReverseRecursive(pHead->m_pNext);
	}

	cout << pHead->m_nValue << " ";
}

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;

	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL)
			pReversedHead = pNode;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}


int main()
{
	ListNode* list = NULL;
	ListNode** pList = &list;
	int value[] = {23, 24, 14, 35, 9, 10, 29, 15};
	for (int i = 0; i < sizeof(value) / sizeof(value[0]); ++i) 
	{
		AddToTail(pList, value[i]);
	}
	
	cout << "PrintList:" << endl;
	PrintList(list);
	cout << endl;

	RemoveNode(pList, value[2]);

	cout << "PrintList:" << endl;
	PrintList(list);
	cout << endl;
			
	cout << "PrintListReverseIterative:" << endl;
	PrintListReverseIterative(list);
	cout << endl;

	cout << "PrintListReverseRecursive:" << endl;
	PrintListReverseRecursive(list);
	cout << endl;

	ListNode* reverseLise = ReverseList(list);
	cout << "ReverseList:" << endl;
	PrintList(reverseLise);
	cout << endl;

	system("pause");
	return 0;
}
