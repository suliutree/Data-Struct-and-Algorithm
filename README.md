# Data-Struct-and-Algorithm
采用C\C++实现大多数的数据结构和部分算法

目的：练习数据结构和算法

编译环境：vs2010


计划：
* 实现数组相关的部分算法
* 实现字符串相关的部分算法
* 实现链表List以及与其相关的部分算法
* 实现树Tree以及与其相关的部分算法
* 实现栈Stack和队列Queue
* 实现查找和排序算法
* 实现位运算的相关算法


进度：

● 数组相关部分算法

    ○ FindSortedMatrix.cpp
        二维数组，每行从左到右递增，每列从上到下递增
        输入这样的一个二维数组和整数，判断数组中是否含有该整数
        
    ○ ReorderOddEven.cpp
        调整数组顺序，使奇数位于偶数前面
        
    ○ FindGreatestSumOfSubArray.cpp
        连续子数组的最大和（整数数组，有整数也有负数）
        
    ○ FirstNotRepeatingChar.cpp
        在字符串中找出第一个只出现一次的字符
        
    
● 字符串相关部分算法

● 链表List相关部分算法

    ○ List.cpp
        AddToTail() 向链表末尾添加一个尾结点
        
        RemoveNode() 删除指定的结点
        
        PrintList() 打印List
        
        PrintListReverseIterative() 从尾到头打印链表（迭代）
        
        PrintListReverseRecursive() 从尾到头打印链表（递归）
        
        ReverseList() 反转链表
        

● 树tree相关部分算法

    ○ Tree.cpp
        CreateTree() 通过输入创建树
        
        Preorder() 前序遍历
        
        Inorder() 中序遍历
        
        Postorder() 后序遍历
        
        PreorderIteration() 非递归前序遍历
        
        InorderIteration() 非递归中序遍历
        
        PostorderIteration() 非递归后序遍历
        
        Levelorder() deque层序遍历
        
        Levelorder1() queue层序遍历
        
        TreeDepth() 树的高度
        
        IsBalanced() 判断是否是平衡二叉树
        
        GetMaximumDistance() 计算二叉树的最大距离（最大宽度）
        
    ○ ConstructTree.cpp
        输入某二叉树的前序遍历和中序遍历的结果，重建出该二叉树
     
    ○ HasSubTree.cpp
        输入两棵二叉树tree1和tree2，判断tree2是不是tree1的子结构
        
    ○ TrieTree.cpp
        给定一个字符串的集合，每次询问时给出一个字符串，求以该字符串为前缀的字符串
        在集合中有多少个
        
        
● 栈Stack和队列Queue相关部分算法

    ○ StackWithMax.cpp
        定义栈的数据结构，在改类型中实现了一个能够得到栈的最大元素的getMax() 函数
        
    ○ TwoStackImplementQueue.cpp
        用两个栈实现一个队列
        enqueue() 在队列尾部插入结点
        
        dequeue() 在队列头部删除结点
        
    ○ SortStack.cpp
        利用两个栈实现数据的顺序输出
        

● 查找和排序算法

    ○ MergeSort.cpp
        归并排序
        
    ○ QuickSort.cpp
        快速排序
        
    ○ QuickSelect.cpp
         快速选择算法：在O(n)的时间内从一个无序数组中返回第K大的元素
         
    
● 位运算相关算法

