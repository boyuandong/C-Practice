/* Z字形变换.cpp
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z(N) 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 
示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string convert1(string s, int numRows)
    {
        // time: O(N), space: O(N)
        if (numRows == 1)
            return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (int i = 0; i < rows.size(); i++)
            ret += rows[i];
        return ret;
    }
    string convert(string s, int numRows)
    {
        // time: O(N), space: O(N), 返回字符串不被视为额外空间，则复杂度为 O(1)
        if (numRows == 1)
            return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    cout << (s.convert1("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR" ? "Passed" : "Falied") << endl;
    cout << (s.convert1("PAYPALISHIRING", 4) == "PINALSIGYAHRPI" ? "Passed" : "Falied") << endl;
    cout << (s.convert1("A", 1) == "A" ? "Passed" : "Falied") << endl;
    cout << endl;
    cout << (s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR" ? "Passed" : "Falied") << endl;
    cout << (s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI" ? "Passed" : "Falied") << endl;
    cout << (s.convert("A", 1) == "A" ? "Passed" : "Falied") << endl;
}