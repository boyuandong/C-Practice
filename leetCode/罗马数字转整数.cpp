// 罗马数字转整数.cpp
/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

 

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        // Solution 1: runtiom error
        /*
        int num=0;
        int i=s.size()-1;
        while(i>=0)
        {
            switch(s[i])
            {
                case 'I': 
                {
                    num += 1; 
                    i--;
                    break;
                }
                case 'V':
                {
                    if(s[i-1] == 'I')
                    {
                        num += 4;
                        i -= 2;
                        break;
                    }
                    num += 5;
                    i--;
                    break;
                }
                case 'X':
                {    if(s[i-1] == 'I')
                    {
                        num += 9;
                        i -= 2;
                        break;
                    }
                    num += 10;
                    i--;
                    break;
                }
                case 'L':
                {
                    if(s[i-1] == 'X')
                    {
                        num += 40;
                        i -= 2;
                        break;
                    }
                    num += 50;
                    i--;
                    break;
                }
                case 'C':
                {
                    if(s[i-1] == 'X')
                    {
                        num += 90;
                        i -=2;
                        break;
                    }
                    num += 100;
                    i--;
                    break;
                }
                case 'D':
                {
                    if(s[i-1] == 'C')
                    {
                        num += 400;
                        i -=2;
                        break;
                    }
                    num += 500;
                    i--;
                    break;
                }
                case 'M':
                {
                    if(s[i-1] == 'C')
                    {
                        num += 900;
                        i -= 2;
                        break;
                    }
                    num += 1000;
                    i--;
                    break;
                }
            }
        }
        return num;
        */

        // Solution 2: use the map
        /*
        map<char, int> keyMap;
        keyMap['I'] = 1;
        keyMap['V'] = 5;
        keyMap['X'] = 10;
        keyMap['L'] = 50;
        keyMap['C'] = 100;
        keyMap['D'] = 500;
        keyMap['M'] = 1000;
        // OR Replace all and do below
        //    keyMap['A'] = 4;
        //    keyMap['B'] = 9;
        //    keyMap['E'] = 40;
        //    keyMap['F'] = 90;
        //    keyMap['G'] = 400;
        //    keyMap['H'] = 900;
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && keyMap.at(s[i]) < keyMap.at(s[i + 1]))
            {
                num -= keyMap.at(s[i]);
            }
            else
            {
                num += keyMap.at(s[i]);
            }
        }
        return num;
        */

        // Solution 3:
        s = replaceAll(s, "IV", "A");
        s = replaceAll(s, "IX", "B");
        s = replaceAll(s, "XL", "E");
        s = replaceAll(s, "XC", "F");
        s = replaceAll(s, "CD", "G");
        s = replaceAll(s, "CM", "H");
        map<char, int> keyMap;
        keyMap['I'] = 1;
        keyMap['V'] = 5;
        keyMap['X'] = 10;
        keyMap['L'] = 50;
        keyMap['C'] = 100;
        keyMap['D'] = 500;
        keyMap['M'] = 1000;
        keyMap['A'] = 4;
        keyMap['B'] = 9;
        keyMap['E'] = 40;
        keyMap['F'] = 90;
        keyMap['G'] = 400;
        keyMap['H'] = 900;
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            num += keyMap.at(s[i]);
        }
        return num;
    }
    string replaceAll(string s, string a, string b)
    {
        while (s.find(a) != string::npos)
        {
            s.replace(s.find(a), a.size(), b);
        }
        return s;
    }
};

int main()
{

    Solution s;
    int test1 = s.romanToInt("III");
    int test2 = s.romanToInt("IV");
    int test3 = s.romanToInt("IX");
    int test4 = s.romanToInt("LVIII");
    int test5 = s.romanToInt("MCMXCIV");
    cout << test5 << endl;
    string t = "MXIVC";
    // string a = "IV";
    // string b = "A";
    // cout<<t.find(a)<<endl;
    // cout<<a.size()<<endl;
    // cout<<t.replace(t.find(a), a.size(), "A")<<endl;
    // cout << s.replaceAll(t, "IV", "A") << endl;
    // cout<<(t.find("C")==string::npos)<<endl;
}