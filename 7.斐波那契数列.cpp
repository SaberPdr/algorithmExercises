/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39

思路
经典的斐波那契数列, 没啥好分析的, 不用递归避免栈溢出就好了.
*/

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
		int a = 1;
        int b = 1;
        n--;
        while(n--)
            a = (b += a) - a;
        return a;
    }
};
