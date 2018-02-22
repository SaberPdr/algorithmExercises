/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
思路
STL 中有全排列函数 next_permutation(), 嘿嘿嘿, 感觉自己在用 python.
*/


class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        int n = str.length();
        if(!n) return res;
        sort(str.begin(), str.end());//先把字符串升序排列
        do{
            res.push_back(str);
        }while(next_permutation(str.begin(), str.end()));
        //全排列函数,将输入数组变成字典序的下一个全排列,因此使用前需要先将数组进行升序排列
        return res;
    }
};


//STL中next_permutation()的实现
template <class T>
bool next_permutation(T first, T last) {
  if (first == last)//空区间
    return false;
  T i = __first;
  ++i;
  if (i == last)//只有一个元素
    return false;
  i = last;//i指向尾端, 最后一个元素之后的位置
  --i;//现在指向最后一个元素

  for(;;) {
    T ii = i;
    --i;
    //以上锁定一组(两个)相邻元素
    if (*i < *ii) {//找到前一个元素小于后一个元素
      T j = last;//令 j 指向尾端
      while (!(*i < *--j))//由尾端往前找, 直到遇到比 *i 大的第一个元素
        {}
      iter_swap(i, j);//交换 i, j
      reverse(ii, last);//将 ii 之后(包括ii) 的元素逆序
      return true;
    }
    if (i == first) {//进行到最前面了
      reverse(first, last);//将全部元素逆序
      return false;
    }
  }
}
