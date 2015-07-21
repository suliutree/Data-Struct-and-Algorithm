#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct TreeNode
{
	int m_nValue;
	vector<TreeNode*> m_vChildren;
};

TreeNode* CreateTreeNode(int value)
{
	TreeNode* pNode = new TreeNode();
	pNode->m_nValue = value;

	return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild)
{
	if (pParent != NULL)
		pParent->m_vChildren.push_back(pChild);
}


/*********************************************************************/

// 函数用来得到从根结点pRoot开始到达结点pNode的路径，保存在path中
bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path)
{
	if (pRoot == pNode)
		return true;

	path.push_back(pRoot);

	bool found = false;

	vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
	while (!found && i < pRoot->m_vChildren.end())
	{
		found = GetNodePath(*i, pNode, path);
		++i;
	}

	if (!found)
		path.pop_back();

	return found;
}

// 用来得到两个路径的最后一个公共结点
TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
{
	list<TreeNode*>::const_iterator it1 = path1.begin();
	list<TreeNode*>::const_iterator it2 = path2.begin();

	TreeNode* pLast = NULL;

	while (it1 != path1.end() && it2 != path2.end())
	{
		if (*it1 == *it2)
			pLast = *it1;

		it1++;
		it2++;
	}

	return pLast;
}


TreeNode* GetLastCommmomParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2)
{
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;

	list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}

/*********************************************************************/

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10

int main()
{
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);

	TreeNode* ret = GetLastCommmomParent(pNode1, pNode6, pNode8);
	cout << ret->m_nValue << endl;

	system("pause");
	return 0;
}
