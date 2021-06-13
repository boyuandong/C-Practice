/* 丑数.cpp
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // 动态规划
        int dp[n];
        dp[0] = 1;
        int dp2 = 0, dp3 = 0, dp5 = 0;
        int i = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[dp2] * 2, min(dp[dp3] * 3, dp[dp5] * 5));
            if (dp[i] == dp[dp2] * 2)
                dp2++;
            if (dp[i] == dp[dp3] * 3)
                dp3++;
            if (dp[i] == dp[dp5] * 5)
                dp5++;
        }
        return dp[n - 1];
    }
};
int main()
{
    Solution s;
    cout << s.nthUglyNumber(10) << endl; //12
    for (int i = 1; i < 11; i++)         // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
        cout << s.nthUglyNumber(i) << " ";
    cout << endl;
}