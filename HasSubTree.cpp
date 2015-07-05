#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct BinaryTreeNode
{
	char m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;

	if (pRoot1 == NULL)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return DoseTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoseTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoseTree1HaveTree2(pRoot1, pRoot2);
		if (!result)
			result = HasSubTree(pRoot1->m_pLeft, pRoot2);
		if (!result)
			result = HasSubTree(pRoot1->m_pRight, pRoot2);
	}
	return result;
}


BinaryTreeNode* CreateTree(BinaryTreeNode* pNode)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		pNode = NULL;
	}
	else {
		if ( !(pNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode))) )
			cout << "error" << endl;
		pNode->m_nValue = ch;
		pNode->m_pLeft = CreateTree(pNode->m_pLeft);
		pNode->m_pRight = CreateTree(pNode->m_pRight);
	}
	return pNode;
}


void Preorder(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	cout << pRoot->m_nValue << " ";
	Preorder(pRoot->m_pLeft);
	Preorder(pRoot->m_pRight);
}

void Inorder(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	Inorder(pRoot->m_pLeft);
	cout << pRoot->m_nValue << " ";
	Inorder(pRoot->m_pRight);
}

void Postorder(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	Postorder(pRoot->m_pLeft);
	Postorder(pRoot->m_pRight);
	cout << pRoot->m_nValue << " ";
}

int main()
{
	cout << "create tree1:" << endl;
	BinaryTreeNode* pRoot1 = NULL;
	pRoot1 = CreateTree(pRoot1);

	// 简单的做了一下测试
	cout << "create tree2:" << endl;
	BinaryTreeNode* pRoot2 = new BinaryTreeNode();
	pRoot2->m_nValue = 'a';
	pRoot2->m_pLeft = NULL;
	pRoot2->m_pRight = NULL;

	Preorder(pRoot1);
	cout << endl;
	Preorder(pRoot2);
	cout << endl;

	bool result = HasSubTree(pRoot1, pRoot2);
	string ret = (result == true) ? "yes" : "no";
	cout << "Does tree1 have tree2: " << ret << endl;

	system("pause");
	return 0;
}
