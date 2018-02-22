/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

思路
算法俗称: 打擂算法.

数组特性: 有一个数字出现超过数组长度的一半. 那么如果存在这么一个数, 那么他出现次数比其他所有数出现次数的和还要多. 因此, 可以把元素分成两类, 这个数和不是这个数的数.

遍历数组, 记录一个数和它出现的次数, 遍历下一个数时, 如果是这个数, 次数加一, 不是就减一. 如果次数变成 0 了, 记录下次遍历的数, 次数置为 1. 最后再遍历一遍数组, 统计得到的结果出现次数, 如果满足超过数组大小一半的话, 就得到结果了.

*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int n = 1;
        int res = numbers[0];
        for(int i = 0; i < numbers.size(); i++){
            if(n == 0){
                res = numbers[i];
                n = 1;
            }
            if(numbers[i] == res)
                n++;
            else
                n--;
        }
        n = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(res == numbers[i])
                n++;
        }
        if(2 * n > numbers.size())
            return res;
        else 
            return 0;
    }
};
