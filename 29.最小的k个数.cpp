/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

思路
用最大堆保存最小的k个数, 堆顶是这k个数中最大的, 遍历数组, 如果遇到小于堆顶的, 删除堆顶数字, 让这个数进堆.
multiset是红黑树实现的, 用来实现最大堆.
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k < 1 || k > input.size())
            return vector<int>{};
        multiset<int, greater<int>> leastK;
        multiset<int, greater<int>>::iterator it;
        for(auto i = input.begin(); i != input.end(); i++){
            if(leastK.size() < k)
                leastK.insert(*i);
            else{
                it = leastK.begin();
                if(*i < *it){
                    leastK.erase(it);
                    leastK.insert(*i);
                }
            }
        }
        vector<int> res;
        it = leastK.begin();
        for(int i = 0; i < k;it++, i++){
            res.push_back(*it);
        }
        return res;
    }
};
