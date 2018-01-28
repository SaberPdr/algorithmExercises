/*
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
//首先定位在二维数组左下角, 即array[m][0], 这个点的上方一列均小于它, 右方一行均大于它. 并且向上或向右移动都不会改变这个性质.
//之后在while中判断target与当前数字的大小关系, 将当前数字向上或向右移动, 直到相等. 或者未找到返回false
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
