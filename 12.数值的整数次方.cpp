/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

思路
使用快速幂算法:

把指数写成二进制的形式, 例如计算 73^13, 13的二进制是 1101, 那么 73^13 = 73 * 73^4 * 73^8, 我们只需要计算73^2, 73^4( = 73^2 * 73^2), 73^8( = 73^4 * 73^4), 最后计算一下73 * 73^4 * 73^8即可, 相比直接使用循环计算, 减少了大量重复计算. 最后, 负数幂的话, 计算分母即可.

*/
class Solution {
public:
    double Power(double base, int exponent) {
    	int p = abs( exponent);
        double r = 1.0;
        while (p) {
            if (p & 1)
                r *= base;
            base *= base;
            p >>= 1;
        }
        return ( exponent > 0 ) ? r : 1/r;
    }
};
