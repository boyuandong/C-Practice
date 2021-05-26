/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    if (strs.size() <= 0)
        return "";
    if (strs.size() == 1)
        return strs[0];
    if (strs[0].size() == 0)
        return "";
    for (int index = 0;; index++)
    {
        char ch = strs[0][index];
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].empty())
                return "";
            if (ch != strs[i][index])
                return strs[0].substr(0, index);
            if (strs[i].size() == index)
                return strs[i];
        }
    }
}

int main()
{
    string t1[] = {"flower", "flow", "flight"};
    vector<string> strs1(t1, t1 + sizeof(t1) / sizeof(string));
    string test1 = longestCommonPrefix(strs1);
    cout << "test1: " << test1 << endl;

    string t2[] = {"dog", "racecar", "car"};
    vector<string> strs2(t2, t2 + sizeof(t2) / sizeof(string));
    string test2 = longestCommonPrefix(strs2);
    cout << "test2: " << test2 << endl;

    string t3[] = {"a"};
    vector<string> strs3(t3, t3 + sizeof(t3) / sizeof(string));
    string test3 = longestCommonPrefix(strs3);
    cout << "test3: " << test3 << endl;

    string t4[] = {"ab", "a"};
    vector<string> strs4(t4, t4 + sizeof(t4) / sizeof(string));
    string test4 = longestCommonPrefix(strs4);
    cout << "test4: " << test4 << endl;
    // strs.push_back("flower");
    // strs.push_back("flow");
    // strs.push_back("flight");
    // for(int i=0; i<3; i++)
    //     cout<<strs[i]<<endl;
    // cout<<strs[0][0]<<endl;
    // string t;
    // t.push_back(strs[0][1]);
    // cout<<t<<endl;
    // string s = "this is a test";
    // s.pop_back();
    // cout<<s<<endl;
}