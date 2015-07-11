/************************************************************************/
/* 二叉树中和为某一值得路径                                             */
/************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateTree(BinaryTreeNode* pNode)
{
	int value;
	cin >> value;
	if (value == -1)
	{
		pNode = NULL;
	}
	else
	{
		if ( !(pNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode))))
			cout << "error" << endl;
		pNode->m_nValue = value;
		pNode->m_pLeft = CreateTree(pNode->m_pLeft);
		pNode->m_pRight = CreateTree(pNode->m_pRight);
	}
	return pNode;
}

void FindPath(BinaryTreeNode* pRoot, int exceptdSum, vector<int>& path, int currentSum);

void FindPath(BinaryTreeNode* pRoot, int exceptedSum)
{
	if (pRoot == NULL)
		return;

	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, exceptedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf)
	{
		for (vector<int>::iterator it = path.begin(); it != path.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	path.pop_back();
}

int main()
{
	BinaryTreeNode* pRoot = NULL;
	pRoot = CreateTree(pRoot);

	cout << "Input expectedSum: ";
	int expectedSum;
	cin >> expectedSum;

	FindPath(pRoot, expectedSum);

	system("pause");
	return 0;
}
