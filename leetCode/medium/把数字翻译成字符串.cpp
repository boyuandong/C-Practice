/* 把数字翻译成字符串.cpp
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，
25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    int translateNum(int num)
    {
        // when num is 1 digit <9
        if (num <= 9)
            return 1;
        int n = num % 100;
        // when num is 2 digit num<=9 or num>=26
        if (n <= 9 || n >= 26)
            return translateNum(num / 10);
        else
            return translateNum(num / 10) + translateNum(num / 100);
    }
};
int main()
{
    Solution s;
    cout << s.translateNum(25) << endl;  //2
    cout << s.translateNum(624) << endl; //2
}