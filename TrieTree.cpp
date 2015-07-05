/************************************************************************/
/* 给定一个字符串的集合，每次询问时给出一个字符串，求以该字符串为前缀的字符串
在集合中有多少个*/
/************************************************************************/

#include <iostream>

using namespace std;

const int kind = 26;

struct TreeNode
{
	// 附加变量count记录遍历到该结点形成的字符串出现的次数
	int count;
	TreeNode* next[kind];
	TreeNode()
	{
		count = 1;
		for (int i = 0; i < kind; i++)
			next[i] = NULL;
	}
};

void insert(TreeNode* &root, char* word)
{
	TreeNode* location = root;
	int i = 0, branch = 0;

	if (location == NULL)
	{
		location = new TreeNode();
		root = location;
	}

	while (word[i])
	{
		branch = word[i] - 'a';
		if (location->next[branch])
			location->next[branch]->count++;
		else
			location->next[branch] = new TreeNode();

		i++;
		location = location->next[branch];
	}
}

int search(TreeNode* root, char* word)
{
	TreeNode* location = root;
	int i = 0, branch = 0, ans = 0;

	if (location == NULL)
		return 0;

	while (word[i])
	{
		branch = word[i] - 'a';
		if (!location->next[branch])
			return 0;

		i++;
		location = location->next[branch];
		ans = location->count;
	}
	return ans;
}

int main()
{
	char word[10];
	char ask[10];
	TreeNode* root = NULL;

	cout << "TrieTree：" << endl;
	while (gets(word))
	{
		if (word[0] == '\0')
			break;
		insert(root, word);
	}

	cout << "ask:" << endl; 
	while (gets(ask))
		cout << search(root, ask) << endl;

	return 0;
}

/*
运行结果：

TrieTree:
abc
abcd
ab
bcd
bcde
bb

ask:
ab
3
b
3
bb
1
abcd
1
abcde
0
*/
