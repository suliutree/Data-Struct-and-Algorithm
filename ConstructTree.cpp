/************************************************************************/
/* 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树             */
/************************************************************************/

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int		m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	// 递归结束条件
	if (startPreorder == endPreorder)
	{
		// 这里*startPreorder == *startInorder如果值不相等就不是同一棵树的不同序列
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw exception("Invalid input.");
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		rootInorder++;
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
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
	int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6};
	int length = sizeof(preorder) / sizeof(preorder[0]);

	BinaryTreeNode* root = Construct(preorder, inorder, length);

	cout << "preorder:" << endl;
	Preorder(root);
	cout << endl;
	cout << "inorder:" << endl;
	Inorder(root);
	cout << endl;
	cout << "postorder:" << endl;
	Postorder(root);
	cout << endl;

	system("pause");
	return 0;
}
