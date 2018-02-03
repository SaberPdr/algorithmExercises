/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

思路
空间换时间, 新建一个数组, 顺序扫描原数组两遍, 第一遍见到奇数就 push_back(), 第二遍见到偶数就push_back(), 最后把新数组整体赋值给原数组.
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> a;
        for(int i = 0; i < array.size() ; i++)
        {
            if(array.at(i) % 2 == 1)
                a.push_back(array.at(i));
        }
        for(int i = 0; i < array.size() ; i++)
        {
            if(array.at(i) % 2 == 0)
                a.push_back(array.at(i));
        }
        array = a;
    }
};
