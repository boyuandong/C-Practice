/* 数值的整数次方.cpp
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    double myPow1(double x, int n)
    {
        if (!x)
            return (double)0;
        if (!n)
            return (double)1;
        if (x == 1)
            return 1;
        double res = 1.0;
        while (n > 0)
        {
            res *= x;
            n--;
        }

        while (n < 0)
        {
            res *= (1 / x);
            n++;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1 || x == 0)
            return x;
        if (n == -1)
            return 1 / x;
        double half = myPow(x, n / 2);
        double mod = myPow(x, n % 2);
        return half * half * mod;
    }
};
int main()
{
    Solution s;
    //1024.00000
    cout << (s.myPow1(2.00000, 10)) << endl;
    cout << (s.myPow(2.00000, 10)) << endl;
    //9.26100
    cout << (s.myPow1(2.10000, 3)) << endl;
    cout << (s.myPow(2.10000, 3)) << endl;
    //0.25000
    cout << (s.myPow1(2.00000, -2)) << endl;
    cout << (s.myPow(2.00000, -2)) << endl;
    // 1.00000
    cout << s.myPow1(1.00000, 2147483647) << endl;
    cout << s.myPow(1.00000, 2147483647) << endl;
    // 0.00000
    // cout<<s.myPow1(2.00000, -2147483648)<<endl; // runtime error
    cout << s.myPow(2.00000, -2147483648) << endl;
}