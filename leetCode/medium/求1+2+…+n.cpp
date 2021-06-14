/* 求1+2+…+n.cpp
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qiu-12n-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    int sumNums1(int n)
    {
        // 对于 A && B 这个表达式，如果 A 表达式返回 False,
        // 那么 A && B 已经确定为 False ，此时不会去执行表达式 B
        // 同理，对于逻辑运算符 ||， 对于 A || B 这个表达式，如果 A 表达式返回 True ，
        // 那么 A || B 已经确定为 True ，此时不会去执行表达式 B。
        n && (n += sumNums(n - 1));
        return n;
    }
    int sumNums(int n)
    {
        (!n) || (n += sumNums(n - 1));
        return n;
    }
};
int main()
{
    Solution s;
    cout << s.sumNums1(3) << endl; //9
    cout << s.sumNums(3) << endl;  //9
    cout << s.sumNums1(9) << endl; //45
    cout << s.sumNums(9) << endl;  //45
}