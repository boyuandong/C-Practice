/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int fib1(int n) {
        // Solution 1: recursive, running overtime
        if(n==0 || n==1) return n;
        return (fib1(n-1) % 1000000007) + (fib1(n-2) % 1000000007);
    }
    int fib2(int n) {
        // Solution 2: keep calculating
        // time: O(N), space: O(1)
        if(n==0 || n==1) return n;
        int a=0, b=1, i=0;
        int count = n/2;
        while(i< count)
        {
            a = (a+b) % 1000000007;
            b = (a+b) % 1000000007;
            i++;
        }
        if(n%2 == 0)
            return a;
        else return b;
    }
    int fib3(int n) {
        // Sloution 3: similar to Slution 2
        if(n<=1) return n;
        int a=0, b=1, c;
        for(int i=2; i<=n; i++)
        {
            c = (a+b) % 1000000007;
            a = b;
            b = c;
        }

        return c;
    }
};

int main()
{
    Solution s;
    int test1 = s.fib1(2);
    int test2 = s.fib2(2);
    int test3 = s.fib3(2);
    int test4 = s.fib1(5);
    int test5 = s.fib2(5);
    int test6 = s.fib3(5);
    int test7 = s.fib1(43);
    int test8 = s.fib2(43);
    int test9 = s.fib3(43);

    cout<<"t1: "<<test1<<endl;
    cout<<"t2: "<<test2<<endl;
    cout<<"t3: "<<test3<<endl;
    cout<<"t4: "<<test4<<endl;
    cout<<"t5: "<<test5<<endl;
    cout<<"t6: "<<test6<<endl;
    cout<<"t7: "<<test7<<endl;
    cout<<"t8: "<<test8<<endl;
    cout<<"t9: "<<test9<<endl;
}