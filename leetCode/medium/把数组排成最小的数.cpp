/* 把数组排成最小的数.cpp
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        vector<string> strs;
        string res;
        for (int i = 0; i < nums.size(); i++)
        {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), compare);
        for (int i = 0; i < strs.size(); i++)
        {
            res += strs[i];
        }
        return res;
    }

private:
    static bool compare(const string &a, const string &b)
    {
        return a + b < b + a;
    }
};
int main()
{
    Solution s;
    int test0[] = {10, 2};
    int test1[] = {3, 30, 34, 5, 9};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    cout << s.minNumber(t0) << endl; //102
    cout << s.minNumber(t1) << endl; //3033459
}