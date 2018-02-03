/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

思路
空间换时间, 新建一个数组, 顺序扫描原数组两遍, 第一遍见到奇数就 push_back(), 第二遍见到偶数就push_back(), 最后把新数组整体赋值给原数组.

拓展
另外, STL中有一个 stable_partition(iterator begin, iterator end, 函数名fun) 函数,

函数传入三个参数, 分别为函数作用起止位置, 和一个返回值为bool类型的自定义函数,

函数功能为, 将 fun() 函数返回值为真的放在数组前, 假的放在数组后, 可以在本题中使用.
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

class Solution {
public: 
    bool fun(int n){
        return ((n & 1) == 1);　//奇数返回真 
    }
 
    void reOrderArray(vector<int> &array){ 
        stable_partition(array.begin(), array.end(), fun);
    }
};
