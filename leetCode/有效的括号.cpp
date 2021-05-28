/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        string val;
        for(int i=0; i<s.size(); i++)
        {
            switch(s[i])
            {
                case '(':
                    val += '(';
                    break;
                case '{':
                    val += '{';
                    break;
                case '[':
                    val += '[';
                    break;
                case ')':
                    if(val.back() != '(')
                        return false;
                    val.pop_back();
                    break;
                case '}':
                    if(val.back() != '{')
                        return false;
                    val.pop_back();
                    break;
                case ']':
                    if(val.back() != '[')
                        return false;
                    val.pop_back();
                    break;
            }
        }
        return val.empty();
    }
};

int main()
{
    string test0 = "()";
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "([)]";
    string test4 = "{[]}";
    Solution s;
    cout<<test0<<" : \t"<<(s.isValid(test0)? "true" : "false" )<<endl;
    cout<<test1<<" : \t"<<(s.isValid(test1)? "true" : "false" )<<endl;
    cout<<test2<<" : \t"<<(s.isValid(test2)? "true" : "false" )<<endl;
    cout<<test3<<" : \t"<<(s.isValid(test3)? "true" : "false" )<<endl;
    cout<<test4<<" : \t"<<(s.isValid(test4)? "true" : "false" )<<endl;
}