/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。

输入描述
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

思路
首先判断完整性, 如果根节点为空, return.

开始递归方式交换:

1.交换根节点的左右儿子

2.交换根节点的左儿子的左右儿子

3.交换根节点的右儿子的左右儿子

递归进行. 到达叶节点的儿子结点, 也就是外结点时返回.


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL)
            return;
        TreeNode* lz = NULL;
        lz = pRoot -> left;
        pRoot -> left = pRoot -> right;
        pRoot -> right = lz;
        Mirror(pRoot -> left);
        Mirror(pRoot -> right);
    }
};
