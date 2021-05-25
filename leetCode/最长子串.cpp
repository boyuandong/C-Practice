/* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
示例 5:

输入: s = "dvdf"
输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string e;
        int num=0, max=0;
        for(int i=0; i<s.length(); i++)
        {
            // cout<<"e: "<<e<<endl;
            // cout<<"num: "<<num<<"\tmax: "<<max<<endl;
            if(!charInString(s[i],e))
            {
                if(e.empty())
                    e = s[i];
                else
                    e += s[i];
                num++;
            }
            else
            {
                if(max < num)
                    max = num;
                // num = 1;
                // e = s[i];
                e = e.substr(e.find(s[i])+1, e.length());
                e += s[i];
                num = e.size();
            }
        }
        if(max<num) max = num;
        return max;
    }
    bool charInString(char a, string s){
        bool flag = false;
        for(int i=0; i<s.size(); i++)
        {
            if(a == s[i])
                flag = true;
        }  
        // cout<<a<<(flag ? " is in ":" not in ")<<s<<endl;
        return flag;
    }
};

int main()
{
    Solution s;
    int test1 = s.lengthOfLongestSubstring("abcabcac");
    int test2 = s.lengthOfLongestSubstring("bbbbb");
    int test3 = s.lengthOfLongestSubstring("pwwkew");
    int test4 = s.lengthOfLongestSubstring("");
    int test5 = s.lengthOfLongestSubstring(" ");
    int test6 = s.lengthOfLongestSubstring("dvdf");
    cout<<test1<<endl;
}