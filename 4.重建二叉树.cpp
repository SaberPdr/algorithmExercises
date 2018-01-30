/*
4.重建二叉树
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
思路

前序: 根, 左儿子, 右儿子;

中序: 左儿子, 根, 右儿子;

根据前序遍历得到根节点(第一个值), 题中假设不含重复数字, 可以用 find() 找到根节点在中序遍历里的下标, 这样就得到了根节点的左子树和右子树包含哪些节点.

对左子树和右子树递归执行上述操作, 直到叶节点.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int n = pre.size();
        if(n == 0)
                return nullptr;

        TreeNode* root = new TreeNode(pre[0]);
        vector<int>::iterator iter_a = find(in.begin(), in.end(), pre[0]);
        int a = iter_a - in.begin();
        vector<int> pre_left,pre_right,in_left,in_right;
        for(int i = 0; i < a; i++)
        {
            pre_left.push_back(pre[i+1]);
            in_left.push_back(in[i]);
        }
        for(int i = a + 1; i < n; i++)
        {
            pre_right.push_back(pre[i]);
            in_right.push_back(in[i]);
        }

        root->left = reConstructBinaryTree(pre_left, in_left);
        root->right = reConstructBinaryTree(pre_right, in_right);
        return root;
    }
};
