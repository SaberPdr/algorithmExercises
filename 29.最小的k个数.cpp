/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

思路
堆排序问题
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size())
            return vector<int>{};
        make_heap(input.begin(), input.end());
        sort_heap(input.begin(), input.end());
        return vector<int>(input.begin(), input.begin() + k);
    }
};
