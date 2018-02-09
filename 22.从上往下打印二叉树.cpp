/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

思路
层次遍历二叉树.

队列实现: 遍历从根节点开始, 首先将根节点入队, 然后开始执行循环: 结点出队, 访问该节点, 其左右儿子入队. 直到队列为空结束.

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* now = q.front();
            result.push_back(now->val);
            if(now->left)
                q.push(now->left);
            if(now->right)
                q.push(now->right);
            q.pop();
        }
        return result;
    }
};
