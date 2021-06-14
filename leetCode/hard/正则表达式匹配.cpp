/* 正则表达式匹配.cpp
请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
状态定义： 设动态规划矩阵 dp ， dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配。
转移方程： 需要注意，由于 dp[0][0] 代表的是空字符的状态， 因此 dp[i][j] 对应的添加字符是 s[i - 1] 和 p[j - 1] 
当 p[j - 1] = '*' 时， dp[i][j] 在当以下任一情况为 true 时等于 true ：
1. dp[i][j - 2]： 即将字符组合 p[j - 2] * 看作出现 0 次时，能否匹配；
2. dp[i - 1][j] 且 s[i - 1] = p[j - 2]: 即让字符 p[j - 2] 多出现 1 次时，能否匹配；
3. dp[i - 1][j] 且 p[j - 2] = '.': 即让字符 '.' 多出现 1 次时，能否匹配；
当 p[j - 1] != '*' 时， dp[i][j] 在当以下任一情况为 true 时等于 true ：
1. dp[i - 1][j - 1] 且 s[i - 1] = p[j - 1]： 即让字符 p[j - 1] 多出现一次时，能否匹配；
2. dp[i - 1][j - 1] 且 p[j - 1] = '.'： 即将字符 . 看作字符 s[i - 1] 时，能否匹配;
初始化： 需要先初始化 dp 矩阵首行，以避免状态转移时索引越界。
1. dp[0][0] = true： 代表两个空字符串能够匹配。
2. dp[0][j] = dp[0][j - 2] 且 p[j - 1] = '*'： 首行 s 为空字符串，因此当 p 的偶数位为 * 时才能够匹配（即让 p 的奇数位出现 0 次，保持 p 是空字符串）。因此，循环遍历字符串 p ，步长为 2（即只看偶数位）。
返回值： dp 矩阵右下角字符，代表字符串 s 和 p 能否匹配。
作者：jyd
链接：https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/jian-zhi-offer-19-zheng-ze-biao-da-shi-pi-pei-dong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isMatch1(string s, string p)
    {
        // 动态规划
        // time: O(MN), space: O(MN)
        if (p.empty())
            return s.empty();
        int m = s.size() + 1, n = p.size() + 1;
        //设动态规划矩阵 dp ， dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配
        vector<vector<bool> > dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        // 初始化首行
        for (int j = 2; j < n; j += 2)
        {
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        }
        // 状态转移
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (p[j - 1] == '*') // 出现 p[j-1]=='*'
                {
                    if (dp[i][j - 2]) // "p[j - 2] *" 出现0次
                        dp[i][j] = true;
                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) // "p[j - 2] *" 出现1次
                        dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == '.') // ".*"组合出现一次
                        dp[i][j] = true;
                }
                else // p[j-1]!='*'
                {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) // p[j-1] 不是 '.'OR'*' 出现字母匹配
                        dp[i][j] = true;
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.') // p[j-1] 是 '.' 可以匹配出现的任意字母
                        dp[i][j] = true;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    bool isMatch(string s, string p)
    {
        // 递归实现
        // time: O(M*N) space: O(M*N)
        if (p.empty())
            return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        // *前字符重复>=1次 || *前字符重复0次（不出现）
        if (p.size() >= 2 && p[1] == '*')
            return (first_match && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        // 不是*，减去已经匹配成功的头部，继续比较
        else
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};
int main()
{
    Solution s;
    cout << (s.isMatch1("aaa", "a.a") ? "pass" : "falied") << endl; //true
    cout << (s.isMatch("aaa", "a.a") ? "pass" : "falied") << endl;  //true
    cout << endl;
    cout << (s.isMatch1("aaa", "ab*ac*a") ? "pass" : "falied") << endl; //true
    cout << (s.isMatch("aaa", "ab*ac*a") ? "pass" : "falied") << endl;  //true
    cout << endl;
    cout << (s.isMatch1("aaa", "aa.a") ? "falied" : "pass") << endl; //false
    cout << (s.isMatch("aaa", "aa.a") ? "falied" : "pass") << endl;  //false
    cout << endl;
    cout << (s.isMatch1("aaa", "ab*a") ? "falied" : "pass") << endl; //false
    cout << (s.isMatch("aaa", "ab*a") ? "falied" : "pass") << endl;  //false
    cout << endl;
    cout << (s.isMatch1("aa", "a") ? "falied" : "pass") << endl; //false
    cout << (s.isMatch("aa", "a") ? "falied" : "pass") << endl;  //false
    cout << endl;
    cout << (s.isMatch1("aa", "a*") ? "pass" : "falied") << endl; //true
    cout << (s.isMatch("aa", "a*") ? "pass" : "falied") << endl;  //true
    cout << endl;
    cout << (s.isMatch1("ab", ".*") ? "pass" : "falied") << endl; //true
    cout << (s.isMatch("ab", ".*") ? "pass" : "falied") << endl;  //true
    cout << endl;
    cout << (s.isMatch1("aab", "c*a*b") ? "pass" : "falied") << endl; //true
    cout << (s.isMatch("aab", "c*a*b") ? "pass" : "falied") << endl;  //true
    cout << endl;
    cout << (s.isMatch1("mississippi", "mis*is*p*.") ? "falied" : "pass") << endl; //false
    cout << (s.isMatch("mississippi", "mis*is*p*.") ? "falied" : "pass") << endl;  //false
}