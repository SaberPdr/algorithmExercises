题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

思路
首先, 看一下二叉搜索树的定义:

二叉搜索树, 它或者是一棵空树, 或者是具有下列性质的二叉树: 若它的左子树不空, 则左子树上所有结点的值均小于它的根结点的值; 若它的右子树不空, 则右子树上所有结点的值均大于它的根结点的值; 它的左、右子树也分别为二叉搜索树.

后序遍历, 也就是按照: "左儿子, 右儿子, 根" 的顺序来遍历.

举例来说:

23.二叉搜索树的后序遍历序列

这是一棵二叉搜索树, 它的后序遍历为: 2, 9, 5, 16, 17, 15, 19, 18, 12.

这个序列的最后一个元素 12 是这棵树的根, 其他元素可以分为两部分, 红色的 2, 9, 5, 是 12 的左子树, 都小于 12, 蓝色的 16, 17, 15, 19, 18, 是 12 的右子树, 都大于 12.

根据定义, 我们知道根的左右子树也分别为二叉搜索树, 所以, 除去最后一个元素是根元素, 它们也可以分为两部分: 2, 9, 5, 和 16, 17, 15, 19, 18. 红色的左子树和蓝色的右子树. 

我们已经找到了规律, 明白了解题的原理, 再写代码就不是一件困难的事了.

代码
class Solution {
    bool judge(vector<int>& a, int first, int last){
        if(first >= last)
            return true;
        int i = first;
        while(i < last && a[i] < a[last])//把i定位在右子树序列的第一个元素
            i++;
        for(int j = i; j < last; j++){//在遍历到根元素前, 如果出现一个小于根的元素, 说明这个序列不满足我们找到的规律
            if(a[j] < a[last])
                return false;
        }
        return judge(a, first, i - 1) && (judge(a, i, last - 1));//对左子树和右子树进行判断
    }
public:
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }
};
