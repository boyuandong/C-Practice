/* 剪绳子.cpp
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int cuttingRope1(int n)
    {
        /*
        1. 任何大于1的数都可由2和3相加组成（根据奇偶证明）
        2. 因为2*2=1*4，2*3>1*5, 所以将数字拆成2和3，能得到的积最大
        3. 因为2*2*2<3*3, 所以3越多积越大 时间复杂度O(n/3)，用幂函数可以达到O(log(n/3)), 因为n不大，所以提升意义不大。 
    空间复杂度常数复杂度O(1)
        */
        if (n <= 3)
            return n - 1;
        int div = n / 3;
        int rem = n % 3;
        long res = 1;
        for (int i = 0; i < div; i++)
        {
            // res *= ( i<div-1?3:(rem==3? 3*rem: (3+rem)) );
            if (i == div - 1)
            {
                if (rem == 2)
                    res *= (3 * rem);
                else
                    res *= (3 + rem);
            }
            else
                res *= 3;
            if (res >= 1000000007)
                res %= 1000000007;
        }
        return (int)res;
    }
    int cuttingRope2(int n)
    {
        // similar to above
        if (n == 1 || n == 2)
            return 1;
        if (n == 3)
            return 2;
        int sum = 1;
        while (n > 4)
        {
            sum *= 3;
            n -= 3;
        }
        return sum * n;
    }
    int cuttingRope(int n)
    {
        // 动态规划 dynamic programming
        if (n <= 3)
            return n - 1;
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            //j<=i/2是因为1*3和3*1是一样的，没必要计算在内，只要计算到1*3和2*2就好了
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        // int Max = dp[n];
        // delete []dp;
        return dp[n];
    }
};
int main()
{
    Solution s;
    cout << s.cuttingRope1(2) << endl; //1
    cout << s.cuttingRope2(2) << endl; //1
    cout << s.cuttingRope(2) << endl;  //1

    cout << s.cuttingRope1(10) << endl; //36
    cout << s.cuttingRope2(10) << endl; //36
    cout << s.cuttingRope(10) << endl;  //36
}