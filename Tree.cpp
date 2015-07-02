#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
	char m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

typedef struct BinaryTreeNode BinaryTreeNode;

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

void PreorderIteration(BinaryTreeNode* pRoot)
{
	stack<BinaryTreeNode*> stack;
	BinaryTreeNode* p = pRoot; // 遍历指针
	while (p || !stack.empty()) { // 栈不空或者p不空时循环
		if (p != NULL) {
			stack.push(p);
			cout << p->m_nValue << " ";
			p = p->m_pLeft;
		} else {
			p = stack.top();
			stack.pop();
			p = p->m_pRight;
		}
	}
}

void InorderIteration(BinaryTreeNode* pRoot)
{
	stack<BinaryTreeNode*> stack;
	BinaryTreeNode* p = pRoot;
	while (p || !stack.empty()) {
		if (p != NULL) {
			stack.push(p);
			p = p->m_pLeft;
		} else {
			p = stack.top();
			cout << p->m_nValue << " ";
			stack.pop();
			p = p->m_pRight;
		}
	}
}

void PostorderIteration(BinaryTreeNode* pRoot)
{
	stack<BinaryTreeNode*> stack;
	BinaryTreeNode* p = pRoot;
	BinaryTreeNode* r = NULL;

	while (p || !stack.empty()) {
		if (p != NULL) { // 走到最左边
			stack.push(p);
			p = p->m_pLeft;
		} 
		else { // 向右
			p = stack.top();
			if (p->m_pRight && p->m_pRight != r) {
				p = p->m_pRight;
				stack.push(p);
				p = p->m_pLeft;
			} 
			else {
				p = stack.top();
				cout << p->m_nValue << " ";
				stack.pop();
				r = p;
				p = NULL;
			}
		}
	}
}

void Levelorder(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size()) {
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);
		if (pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
	}
}

void Levelorder1(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	queue<BinaryTreeNode*> queueTreeNode;
	queueTreeNode.push(pRoot);

	while (queueTreeNode.size()) {
		BinaryTreeNode* pNode = queueTreeNode.front();
		queueTreeNode.pop();
		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft)
			queueTreeNode.push(pNode->m_pLeft);
		if (pNode->m_pRight)
			queueTreeNode.push(pNode->m_pRight);
	}
}

int TreeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;

	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);

	return left > right ? (left + 1) : (right + 1);
}

bool IsBalanced(BinaryTreeNode* pRoot, int* depth)
{
	if (pRoot == NULL) {
		*depth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}

/*
计算一个二叉树的最大距离有两种情况：
1.路径经过左子树的最深结点，通过根节点，再到右子树的最深结点
2.路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者
只需要计算这两个情况的路径距离，并取其大者，就是该二叉树的最大距离
*/
struct RESULT {  // 定义返回结果
	int nMaxDistance; // 最大距离
	int nMaxDepth; // 最大深度
};

RESULT GetMaximumDistance (BinaryTreeNode* pRoot)
{
	if (pRoot == NULL) {
		RESULT empty = {0, -1}; // 最大深度初始化为-1，是因为调用者要对其加1，然后变为0
		return empty;
	}

	RESULT lhs = GetMaximumDistance(pRoot->m_pLeft);
	RESULT rhs = GetMaximumDistance(pRoot->m_pRight);
	RESULT result;
	result.nMaxDepth = max(lhs.nMaxDepth + 1, rhs.nMaxDepth + 1);
	result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), lhs.nMaxDepth + rhs.nMaxDepth + 2);
	return result;
}


int main()
{
	BinaryTreeNode* pRoot = NULL;
	pRoot = CreateTree(pRoot);

	cout << "preorder :" << endl;
	Preorder(pRoot);
	cout << endl;
	cout << "preorderIteration :" << endl;
	PreorderIteration(pRoot);
	cout << endl;

	cout << "inorder :" << endl;
	Inorder(pRoot);
	cout << endl;
	cout << "inorderIteration :" << endl;
	InorderIteration(pRoot);
	cout << endl;

	cout << "postorder :" << endl;
	Postorder(pRoot);
	cout << endl;
	cout << "postorderIteration :" << endl;
	PostorderIteration(pRoot);
	cout << endl;

	cout << "levelorder :" << endl;
	Levelorder(pRoot);
	cout << endl;
	cout << "levelorder1 :" << endl;
	Levelorder1(pRoot);
	cout << endl;

	int treeDepth = TreeDepth(pRoot);
	cout << "treedepth :" << endl;
	cout << treeDepth << endl;

	cout << "isbalanced :" << endl;
	cout << IsBalanced(pRoot) << endl;

	RESULT result = GetMaximumDistance(pRoot);
	cout << "maxdistance :" << endl;
	cout << result.nMaxDistance << endl;

	system("pause");
	return 0;
}
