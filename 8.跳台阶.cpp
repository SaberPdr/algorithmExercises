/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
思路
设青蛙跳台阶的跳法是 f(n), 第一步有两种跳法, 

(1) 跳一步, 这种情况下剩下的 n - 1 个台阶跳法是 f(n - 1)

(2) 跳两步, 这种情况下剩下的 n - 2 个台阶跳法是 f(n - 2)

那么总共的跳法 f(n) = f(n - 1) + f(n - 2). 斐波那契数列喽.
*/
class Solution {
public:
    int jumpFloor(int number) {
        int a = 1;
        int b = 1;
        while(number--)
        {
            a = (b += a) - a;
        }
        return a;
    }
};
