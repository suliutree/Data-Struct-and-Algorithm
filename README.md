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
* hash表相关算法
* 其它相关算法


进度：

####● 数组相关部分算法

    ○ FindSortedMatrix.cpp
        二维数组，每行从左到右递增，每列从上到下递增
        输入这样的一个二维数组和整数，判断数组中是否含有该整数
        
    ○ ReorderOddEven.cpp
        调整数组顺序，使奇数位于偶数前面
        
    ○ FindGreatestSumOfSubArray.cpp
        连续子数组的最大和（整数数组，有整数也有负数）
        
    ○ FirstNotRepeatingChar.cpp
        在字符串中找出第一个只出现一次的字符
        
    ○ InversePairs.cpp
        数组中的逆序对
     
    ○ MoreThanHalfNum.cpp
        找出数组中出现次数超过一半的数字

        
        
<br>
####● 字符串相关部分算法

    ○ ReplaceBlank.cpp
        把字符串的每个空格替换成"%20"，此实现是在原串上直接替换
        
    ○ Permutation.cpp
        字符串的全排列
        
    ○ KMPSearch.cpp
        KMP算法的实现
        
    ○ StrToInt.cpp
        将字符串转化为整数
        
    ○ ReverseSentence.cpp
        翻转句子
        
    ○ LeftRotateString.cpp
        左旋字符串
        
    ○ ProcessString.cpp
        strlen(s)：返回s的长度，不包括字符串结束符null
        strcmp(s1, s2)：比较两个字符串s1和s2是否相同
        strcat(s1, s2)：将字符串s2连接到s1后，并返回s1
        strcpy(s1, s2)：将s2复制给s1，并返回s1
        void* my_memcpy(void* dest, const void* src, size_t n)：从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest
                                                                所指的内存地址的起始位置中
        void* my_memset(void* ptr, int value, size_t n)：将ptr中前n个字节用value替换并返回ptr
        
    ○ StringFilter.cpp
        若字符串中出现多个相同的字符，将非首次出现的字符过滤掉
        
    ○ AddToLargeNum.cpp
        大数相加，两数可为正，可为负，可为一正一负
        
    ○ DelSubStr.cpp
        删除字符串中所有给定的子串
        
    ○ Match.cpp
        正则表达式匹配
        
    ○ BracketPair.cpp
        判断括号是否匹配
    
    
<br>   
####● 链表List相关部分算法

    ○ List.cpp
        AddToTail() 向链表末尾添加一个尾结点
        
        RemoveNode() 删除指定的结点
        
        PrintList() 打印List
        
        PrintListReverseIterative() 从尾到头打印链表（迭代）
        
        PrintListReverseRecursive() 从尾到头打印链表（递归）
        
        ReverseList() 反转链表
        
    ○ FindKthToTail.cpp
        链表中倒数第k个结点
        
    ○ FindFirstCommonNode.cpp
        两个链表的第一个公共结点
        
    ○ MidPoint.cpp
        返回链表的中间结点
        
    ○ FindLoop.cpp
        链表中环的入口节点
        
    ○ LastNumberInCircle.cpp
        圆圈中最后剩下的数字
        
    ○ DeleteNodeInList.cpp
        O(1)的时间删除单链表的结点
        
<br>
####● 树tree相关部分算法

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
        
    ○ GetLastCommonParent.cpp
        树（普通树）中两个结点的最低公共祖先
        
    ○ tree.md
        AVL树，红黑树，B/B+树，Trie树各自的应用场景。
    
<br>       
####● 栈Stack和队列Queue相关部分算法

    ○ StackWithMax.cpp
        定义栈的数据结构，在改类型中实现了一个能够得到栈的最大元素的getMax() 函数
        
    ○ TwoStackImplementQueue.cpp
        用两个栈实现一个队列
        enqueue() 在队列尾部插入结点
        
        dequeue() 在队列头部删除结点
        
    ○ SortStack.cpp
        利用两个栈实现数据的顺序输出
        
    ○ InfixToSuffix.cpp
        中缀表达式转化为后缀表达式
        

<br>
####● 查找和排序算法

    ○ MergeSort.cpp
        归并排序
        
    ○ QuickSort.cpp
        快速排序
        
    ○ QuickSelect.cpp
        快速选择算法：在O(n)的时间内从一个无序数组中返回第K大的元素
         
    ○ HeapSort.cpp
        归并排序
    
         
<br>  
####● 位运算相关算法

    ○ NumberOf1.cpp
        输入一个整数，输出该数二进制表示中1的个数
        
    ○ FindNumberAppearOnce.cpp
        一个整型数组里除了两个数字之外，其他的数字都出现了两次，找出这两个数字
        
    ○ AddTwoNum.cpp
        不用加减乘除四则运算符号计算两个整数的和
        
    ○ ReverseBits.cpp
        对一个32位的无符号整数反转二进制


<br>
####● hash表相关算法

    ○ IsUnique.cpp
        判断一个字符串中每个字符是不是唯一的
        
    ○ IsPermutation.cpp
        判断两个字符串是不是同一个字符串的不同排列
        
    ○ CanCompose.cpp
        判断一个字符串中出现的字符是否可以组成另一个字符串
        
    ○ AddToTarget.cpp
        找出数组中两个元素的和等于target，返回其下标
        
    ○ LenOfLongestConsecutiveSeq.cpp
        最长连续子数组的长度
        
<br>
####● 其它相关算法

    ○ PrintNPrime.cpp
        输出前N个素数。不需要考虑整数溢出问题，也不需要使用大数处理算法
