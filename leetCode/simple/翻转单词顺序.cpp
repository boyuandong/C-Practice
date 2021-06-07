/* 翻转单词顺序.cpp
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
例如输入字符串"I am a student. "，则输出"student. a am I"。
示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <stack>
#include<sstream>
using namespace std;
class Solution
{
public:
    string reverseWords1(string s)
    {
        // using loops
        // runtime high, space low
        bool flag = false;
        bool last = false;
        string ans;
        string word;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                word += s[i];
            else if (!word.empty())
                flag = true;
            if (i == s.size() - 1 && !word.empty())
                flag = true;
            if (flag)
            {
                ans.insert(0, word);
                if (i < s.size() - 1)
                    ans.insert(0, " ");
                flag = false;
                word.clear();
            }
        }
        while (ans[0] == ' ')
        {
            ans.erase(0, 1);
        }
        return ans;
    }
    string reverseWords2(string s)
    {
        // using the stack
        // runtime faster than method 1
        stack<string> words;
        bool flag = false;
        string word;
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                word += s[i];
            else if (!word.empty())
            {
                flag = true;
            }
            if (i == s.size() - 1 && !word.empty())
                flag = true;
            if (flag)
            {
                words.push(word);
                word.clear();
                flag = false;
            }
        }
        while (!words.empty())
        {
            if (words.size() > 1)
            {
                ans += words.top();
                ans += ' ';
            }
            else
                ans += words.top();
            words.pop();
        }
        return ans;
    }
    string reverseWords(string s)
    {
        // using #include<sstream>
        // using too much space
        string ans;
        string word;
        stringstream ss(s);
        while (ss>>word)
        {
            ans = word +' '+ans;
        }
        ans.pop_back();
        return ans;
        
    }
};

int main()
{
    Solution s;
    string test0 = "the sky is blue";
    string test1 = "  hello world!  ";
    string test2 = "a good   example";
    cout << "[" << test0 << "]"
         << "\n"
         << "[" << s.reverseWords(test0) << "]" << endl;
    cout << "[" << test1 << "]"
         << "\n"
         << "[" << s.reverseWords(test1) << "]" << endl;
    cout << "[" << test2 << "]"
         << "\n"
         << "[" << s.reverseWords(test2) << "]" << endl;
}