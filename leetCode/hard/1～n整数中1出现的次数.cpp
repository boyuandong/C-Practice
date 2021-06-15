/* 1～n整数中1出现的次数.cpp 
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。 
示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
using namespace std;
class Solution
{
private:
    int count1(int n)
    {
        int count = 0;
        while (n)
        {
            if (n % 10 == 1)
                count++;
            n /= 10;
        }
        return count;
    }
    int count_str(string n)
    {
        int count = 0;
        for (int i = 0; i < n.size(); i++)
            if (n[i] == '1')
                count++;
        return count;
    }

public:
    int countDigitOne1(int n)
    {
        // loops count one by one
        // running overtime
        // time O(N^2)
        int count = 0;
        for (int i = 1; i <= n; i++)
            count += count1(i);
        return count;
    }
    int countDigitOne2(int n)
    {
        // loops count one by one
        // running overtime
        // time O(N^2)
        int count = 0;
        for (int i = 1; i <= n; i++)
            count += count_str(to_string(i));
        return count;
    }
    int countDigitOne(int n)
    {
        // mathmetical way
        // num = high cur low
        // time: O(logN)
        int count = 0;
        long high = n / 10;
        long cur = n % 10;
        long low = 0;
        long digit = 1;
        while (high != 0 || cur != 0)
        {
            if (cur == 0)
                count += (high * digit);
            else if (cur == 1)
                count += (high * digit) + low + 1;
            else if (cur > 0)
                count += (high * digit) + digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return count;
    }
};
int main()
{
    Solution s;

    cout << (s.countDigitOne1(12) == 5 ? "Passed" : "Falied") << endl;
    cout << (s.countDigitOne2(12) == 5 ? "Passed" : "Falied") << endl;
    cout << (s.countDigitOne(12) == 5 ? "Passed" : "Falied") << endl;
    cout << endl;
    cout << (s.countDigitOne1(13) == 6 ? "Passed" : "Falied") << endl;
    cout << (s.countDigitOne2(13) == 6 ? "Passed" : "Falied") << endl;
    cout << (s.countDigitOne(13) == 6 ? "Passed" : "Falied") << endl;
    cout << endl;
    cout << (s.countDigitOne1(145) == 81 ? "Passed" : "Falied") << endl;
    cout << (s.countDigitOne2(145) == 81 ? "Passed" : "Falied") << endl;
    cout << (s.countDigitOne(145) == 81 ? "Passed" : "Falied") << endl;
    cout << endl;
    // cout<<s.countDigitOne1(824883294)<<endl;// running overtime wrong!
    // cout<<s.countDigitOne2(824883294)<<endl;// running overtime wrong!
    cout << (s.countDigitOne(824883294) == 767944060 ? "Passed" : "Falied") << endl;
    cout << endl;
    // cout<<s.countDigitOne1(1410065408)<<endl;// running overtime wrong!
    // cout<<s.countDigitOne2(1410065408)<<endl;// running overtime wrong!
    cout << (s.countDigitOne(1410065408) == 1737167499 ? "Passed" : "Falied") << endl;
}