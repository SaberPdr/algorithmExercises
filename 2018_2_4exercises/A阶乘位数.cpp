/*
链接：https://www.nowcoder.net/acm/contest/75/A
来源：牛客网

题目描述 
夫夫有一天对一个数有多少位数感兴趣，但是他又不想跟凡夫俗子一样，
所以他想知道给一个整数n，求n！的在8进制下的位数是多少位。
输入描述:
第一行是一个整数t(0<t<=1000000)(表示t组数据)
接下来t行，每一行有一个整数n(0<=n<=10000000)
输出描述:
输出n！在8进制下的位数。
示例1
输入
3
4
2
5
输出
2
1
3
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while(t--){
        scanf("%d",&n);
        n > 1 ? printf("%d\n", (int)ceil((log(2*acos(-1.0)*n)/2+n*log(n)-n)/log(8))) : puts("1");
    }
}

#include<stdio.h>
#include<math.h>
#define pi 3.1415926535898
#define e 2.718281828459
int main()
{
    int t,n,ws;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==0) ws=1;
        else
        ws=((log10(2*pi*n))/2+n*log10(n/e))/log10(8)+1;
        printf("%d\n",ws);
    }
    return 0;
}

