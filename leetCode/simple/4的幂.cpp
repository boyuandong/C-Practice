/*  4的幂.cpp
给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

示例 1：

输入：n = 16
输出：true
示例 2：

输入：n = 5
输出：false
示例 3：

输入：n = 1
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<cmath>
using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // log(4^n)=n*log(4)
        if (n <= 0)
            return false;
        int num = log(n) / log(4);
        return num * log(4) == log(n);
    }
};

int main()
{
    Solution s;
    cout << "4: " << s.isPowerOfFour(4) << endl;
    cout << "5: " << s.isPowerOfFour(5) << endl;
    cout << "-1: " << s.isPowerOfFour(-1) << endl;
    cout << "32: " << s.isPowerOfFour(32) << endl;
    cout << "64: " << s.isPowerOfFour(64) << endl;
}