/* 字符串的排列.cpp
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> permutation(string s)
    { // better faster
        vector<string> ans;
        dfs(ans, s, 0);
        return ans;
    }
    vector<string> permutation2(string s)
    {
        vector<string> ans;
        dfs2(ans, s, 0);
        return ans;
    }
    void dfs(vector<string> &ans, string &s, int pos)
    {
        if (pos == s.size())
            ans.push_back(s);
        for (int i = pos; i < s.size(); i++)
        {
            bool flag = true;
            for (int j = pos; j < i; j++) //字母相同时，等效，剪枝
            {
                if (s[j] == s[i])
                    flag = false;
            }
            if (flag)
            {
                swap(s[pos], s[i]);
                dfs(ans, s, pos + 1);
                swap(s[pos], s[i]);
            }
        }
    }
    void dfs2(vector<string> &res, string s, int x)
    {
        if (x == s.size() - 1)
        {
            res.push_back(s); // 添加排列方案
            return;
        }
        set<int> st;
        for (int i = x; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
                continue; // 重复，因此剪枝
            st.insert(s[i]);
            swap(s[i], s[x]);    // 交换，将 s[i] 固定在第 x 位
            dfs2(res, s, x + 1); // 开启固定第 x + 1 位字符
            swap(s[i], s[x]);    // 恢复交换
        }
    }
};
void PrintV(vector<string> v)
{
    cout << "[";
    int i;
    for (i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[i] << "]" << endl;
}
int main()
{
    Solution s;
    vector<string> t0 = s.permutation("abc");
    vector<string> t1 = s.permutation("abb");
    vector<string> t2 = s.permutation2("abc");
    vector<string> t3 = s.permutation2("abb");
    PrintV(t0);
    PrintV(t1);
    PrintV(t2);
    PrintV(t3);
}
