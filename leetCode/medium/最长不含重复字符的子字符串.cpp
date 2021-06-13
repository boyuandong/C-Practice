/* 最长不含重复字符的子字符串.cpp
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring1(string s)
    {
        int res = 0;
        set<char> Myset;
        for (int l = 0, r = 0; r < s.size(); r++)
        {
            char a = s[r];
            while (Myset.count(a))
                Myset.erase(s[l++]);
            Myset.insert(a);
            res = max(res, r - l + 1);
        }
        return res;
    }
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        string str;
        int l = 0, r = 0;
        while (r < s.size())
        {
            while (str.find(s[r]) != string::npos)
            {
                str.erase(str.begin());
                l++;
            }
            str.push_back(s[r]);
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring1("abcabcbb") << endl; //3
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;  //3
    cout << endl;
    cout << s.lengthOfLongestSubstring1("bbbbb") << endl; //1
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;  //1
    cout << endl;
    cout << s.lengthOfLongestSubstring1("pwwkew") << endl; //3
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;  //3
    cout << endl;
    cout << s.lengthOfLongestSubstring1("dvdf") << endl; //3
    cout << s.lengthOfLongestSubstring("dvdf") << endl;  //3
}