/* 最长回文子串.cpp
给你一个字符串 s，找到 s 中最长的回文子串。
示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<bool> > dp(n, vector<bool>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++)
        {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++)
            {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n)
                    break;
                // 看两侧是否符合回文
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
int main()
{
    Solution s;
    cout << (s.longestPalindrome("babad") == "bab" ? "Passed" : "Falied") << endl;
    cout << (s.longestPalindrome("cbbd") = "bb" ? "Passed" : "Falied") << endl;
    cout << (s.longestPalindrome("a") == "a" ? "Passed" : "Falied") << endl;
    cout << (s.longestPalindrome("ac") == "a" ? "Passed" : "Falied") << endl;
    cout << (s.longestPalindrome("bb") == "bb" ? "Passed" : "Falied") << endl;
}