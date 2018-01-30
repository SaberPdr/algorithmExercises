/*
1.二维数组中的查找
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
思路

二维数组类似下面这个:

1   2   3   4
5   6   7   8 
9   10  11  12
13  14  15  16

首先可以发现在二维数组左下角, 即13这个点, 它的上方一列均小于它, 右方一行均大于它. 并且这个点向上或向右移动都不会改变这个性质.

判断当前数字与target的大小关系, 若大于target则向上移动, 小于则向右移动, 直到相等返回. 或者未找到返回false.
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int k = 0;
        int m = array.size()-1;

        while(k < array[m].size() && m >= 0)
        {
                if(target == array[m][k])
                        return true;
                else if(target < array[m][k])
                        m--;
                else if(target > array[m][k])
                        k++;
        }
        return false;
        
    }
};
