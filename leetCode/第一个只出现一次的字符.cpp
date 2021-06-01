/* 第一个只出现一次的字符.cpp
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <map>
#include <string>
#include<vector>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        map<char, int> myMap;
        for (int i = 0; i < s.size(); i++)
        {
            myMap[s[i]]++;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(myMap[s[i]] == 1)
                return s[i];
        }
        return ' ';
    }

    char firstUniqChar1(string s) {
        // use a dictionary
        if(s.empty())
            return ' ';
        vector<int> dic(26,0);
        for(int i=0; i<s.size(); i++)
        {
            dic[s[i]-'a']++;
        }
        for(int i =0; i<s.size(); i++)
        {
            if(dic[s[i]-'a'] == 1)
                return s[i];
        }
        return ' ';
    }
};

int main()
{
    Solution s;
    string t0 = "leetcode";
    string t1 = "loveleetcode";
    string t2 = "cc";
    // s.firstUniqChar1(t0);
    cout<<s.firstUniqChar(t0)<<endl;
    cout<<s.firstUniqChar(t1)<<endl;
    cout<<s.firstUniqChar(t2)<<endl;
    cout<<endl;
    cout<<s.firstUniqChar1(t0)<<endl;
    cout<<s.firstUniqChar1(t1)<<endl;
    cout<<s.firstUniqChar1(t2)<<endl;
}