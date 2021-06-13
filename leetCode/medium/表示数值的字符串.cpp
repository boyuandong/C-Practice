/* 表示数值的字符串.cpp
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <cstring>
using namespace std;
class Solution
{
private:
    int i = 0;
    bool number = false;
    void is0_9(string s)
    {
        while (s[i] >= '0' && s[i] <= '9')
        {
            number = true;
            i++;
        }
    }
    void isBlank(string s)
    {
        while (i < s.size() && s[i] == ' ')
            i++;
    }

public:
    bool isNumber(string s)
    {
        isBlank(s);
        if (s[i] == '+' || s[i] == '-')
            i++;
        is0_9(s);
        if (s[i] == '.')
        {
            i++;
            is0_9(s);
        }
        if (s[i] == 'e' || s[i] == 'E')
        {
            if (!number)
                return false;
            number = false;
            i++;
            if (s[i] == '+' || s[i] == '-')
                i++;
            is0_9(s);
        }
        isBlank(s);
        if (i == s.size() && number)
            return true;
        return false;
    }
};

int main()
{
    string test[] = {"0", "e", ".", "    .1 ", "+100", "5e2", "-123", "3.1416", "-1E-16", "0123", "12e", "1a3.14", "1.2.3", "+-5", "12e+5.4", " ", "e9", "3.", ". 1", "53K", "6+1", ".5", "..2"};
    string ans[] = {"true", "false", "false", "true", "true", "true", "true", "true", "true", "true", "false", "false", "false", "false", "false", "false", "false", "true", "false", "false", "false", "true", "false"};
    int N = sizeof(test) / sizeof(test[0]);
    string sol[N];
    for (int k = 0; k < N; k++)
    {
        Solution s; // !!!! attention, need to use the new created object each time
        sol[k] = (s.isNumber(test[k]) ? "true" : "false");
        if (sol[k] != ans[k])
        {
            cout << "test[" << k << "]=" << test[k] << " \tsol[i]=" << sol[k] << "\tans[i]=" << ans[k] << endl;
            // break;
        }
    }
    cout << "all done" << endl;
}