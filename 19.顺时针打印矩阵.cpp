/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵：

1 2 3 4 
5 6 7 8
9 10 11 12 
13 14 15 16
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

思路
每次打印出第一行,

1,2,3,4
然后删除第一行, 将剩余矩阵逆时针旋转90度,

8,12,16
7,11,15
6,10,14
5,9,13
重复上两步, 打印第一行, 删除, 旋转, 直到行数或列数为0;

*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> re;
        while(matrix.size()){
            int m = matrix[0].size();	//列数
            int n = matrix.size();		//行数
            for(int i = 0; i < m; i++){
                re.push_back(matrix[0][i]);
            }
            matrix.erase(matrix.begin());	//删除已打印的首行
            if(matrix[0].size() == 0 || matrix.size() == 0)
                break;
            matrix = turn(matrix);
        }
        return re;
    }
private:
    vector<vector<int>> turn(vector<vector<int>>& matrix) {//逆时针旋转二维vector90度
        int m = matrix[0].size();	//列数
        int n = matrix.size();		//行数
        vector<vector<int>> temp(m, vector<int>(n));
        for(int i = 0; i < m; i++){//顺时针旋转二维vector 90度
            for(int j = 0; j < n; j++){
                temp[i][j] = matrix[j][i];
            }
        }
        reverse(temp.begin(), temp.end());//再翻转vector, 和上面的顺时针旋转合一起就是逆时针90度
        return temp;
    }
};
