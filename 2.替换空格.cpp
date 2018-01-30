
/*
2.替换空格
题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
思路

看上去似乎只要把字符串从头扫描到尾, 遇到空格就替换就行了. 问题在于, 字符串本质是数组, 空格是一个字符, 要替换成”%20″三个字符, 替换后字符串要变长, 这意味着空格之后的所有字符都要后移两位, 一来这是很大的开销, 二来这也不安全, 万一覆盖了后面的数据, 就有可能导致系统崩溃.

所以我们的做法是首先统计空格数目, 计算一下替换后字符串长度是否会大于length, 大于代表会覆盖”/0″之后不属于当前字符串的空间, 则不允许替换.

最后, 为了避免移动数组成员产生的大开销, 我们采取从后向前替换.
*/

class Solution {
public:
    void replaceSpace(char *string,int length) {
        if(string == NULL||length <= 0)
            return;
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while(string[i] != '\0')
        {
            ++originalLength;
            if(string[i] == ' ')
                ++numberOfBlank;
            ++i;
        }
        int newLength = originalLength + numberOfBlank * 2;
        if(newLength > length)
            return;
        
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
            if(string[indexOfOriginal] == ' ')
            {
                string[indexOfNew--] = '0';
                string[indexOfNew--] = '2';
                string[indexOfNew--] = '%';
            }
            else
                string[indexOfNew--] = string[indexOfOriginal];
            --indexOfOriginal;
        }
    }
};
