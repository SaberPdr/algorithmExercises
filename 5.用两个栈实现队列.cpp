/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
思路
栈(FILO)先进后出, 队列(FIFO)先进先出.

用栈实现队列的话, push()可以不动, pop()时弹出栈底元素即可.

要弹出栈底元素而其他元素不变, 可以将栈A的元素逐个弹出并压入栈B, 只留下栈底元素, 弹出栈底元素, 再把栈B的元素逐个弹出并压入栈A即可.
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack1.size() == 0)
            return -1;
        if(stack1.size() == 1)
        {
            int j = stack1.top();
            stack1.pop();
            return j;
        }
        int size1 = stack1.size();
        for(int i = 0; i < size1; i++)
        {
            int j = 0;
            j = stack1.top();
            stack1.pop();
            stack2.push(j);
        }
        int r = stack2.top();
        stack2.pop();
        int size2 = stack2.size();
        for(int i = 0; i < size2; i++)
        {
            int j = 0;
            j = stack2.top();
            stack2.pop();
            stack1.push(j);
        }
        return r;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
