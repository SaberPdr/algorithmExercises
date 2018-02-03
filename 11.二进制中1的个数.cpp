/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

思路
负数用补码表示, 那么我们分三种情况讨论:

(1) n = 0, 有 0 个 1;

(2) n > 0, 正数最高位是 0, 把 n 和 1 作与运算, 如果 n 的最低位是 1, 运算结果为 1, 个数加一. 之后把 n 右移一位, 循环进行上述操作直到 n 为 0 结束.

(3) n < 0, 负数最高位是 1, 把最高位先置位成 0 , 个数加一, 再进行 (2) 的操作, 这是为了避免负数右移最高位会补 1, 导致结果不正确.11.二进制中1的个数

*/
class Solution {
public:
     int  NumberOf1(int n) 
     {
        int num = 0;

        if(n == 0)
                return 0;
        if(n > 0)
        {
                int m;
                while(n)
                {
                        m = n & 1;
                        if(m)
                                num++;
                        n >>= 1;
                }
                return num;
        }
        if(n < 0)
        {
                n &= 2147483647;
                num++;
                int m;
                while(n)
                {
                        m = n & 1;
                        if(m)
                                num++;
                        n >>= 1;
                }
                return num;
        }
        return num;
     }
};
