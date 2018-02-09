/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

思路
学习数据结构时候, 这是很常见的一道题, 只不过那时候用笔算, 现在用程序.

这道题的思路很直观, 建立一个实际的栈, 试一试就行了.

按照压栈序列压栈, 压栈过程中每当栈顶元素与出栈序列匹配时就弹栈, 无论如何最终压栈序列的元素都会全部压入栈中, 如果弹出序列正确, 那么所有元素又都会被弹出, 所以最终判断栈是否为空即可得出答案.
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(!pushV.size())
            return false;
        stack<int> s;
        for(int i = 0, j = 0; i < pushV.size(); i++){
            s.push(pushV[i]);
            while(j < popV.size() && s.top() == popV[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
