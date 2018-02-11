/*
题目描述

输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
思路

对二叉树进行深度优先遍历, 把经过的结点记录在数组 temp 中, 到达叶节点时:

    如果 temp 中的值和与给定整数相等, 这个 temp 是一个解.
    如果 temp 中的值与给定整数不等, 把叶节点的值从 temp 中除去, 继续遍历.


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    vector<vector<int> > result;
    vector<int> temp;
    void dfs(TreeNode* root,int left){
        temp.push_back(root->val);
        if(left == root->val && !root->left && !root->right)//如果到达叶节点且路径上值的和与给定整数相等, 那么这就是一个解.
            result.push_back(temp);
        else{//不是解的话, 有左儿子遍历左儿子, 有右儿子遍历右儿子
            if(root->left)
                dfs(root->left, left-root->val);
            if(root->right)
                dfs(root->right, left-root->val);
        }
        temp.pop_back();//这条路径不是解, 删除叶节点返回父节点
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if(root)
            dfs(root, expectNumber);
        return result;
    }
};
