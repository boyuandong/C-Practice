/* 扑克牌中的顺子.cpp
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include<map>
using namespace std;
class Solution
{
public:
    bool isStraight1(vector<int> &nums)
    {
        // A:1, J:11, Q:12, K:13
        sort(nums.begin(), nums.end());
        int zero = 0, diff = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
            {
                zero++;
                continue;
            }
            if (nums[i] == nums[i + 1])
                return false;
            if (nums[i] + 1 != nums[i])
            {
                diff += nums[i + 1] - nums[i] - 1;
            }
        }
        return zero >= diff;
    }
    bool isStraight(vector<int> &nums)
    {
        // 只有5张牌 如果重复，肯定错误。
        // 如果不存在0，则最大值最小值之差必定为4 其他情况，最大值最小值之差小于4即可
        // this one runtime better
        int Min = 14, Max = -1;
        map<int, int> m;
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroCount++;
            else
            {
                Min = min(Min, nums[i]);
                Max = max(Max, nums[i]);
                if (!m.count(nums[i]))
                    m[nums[i]] = 1;
                else
                    m[nums[i]]++;
                if (m[nums[i]] > 1)
                    return false;
            }
        }
        if (!zeroCount)
            return (Max - Min) == 4;
        return (Max - Min) <= 4;
    }
};
int main()
{
    int test0[] = {1, 2, 3, 4, 5};
    int test1[] = {0, 0, 1, 2, 5};
    int test2[] = {9, 10, 4, 0, 9};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    vector<int> t2(test2, test2 + sizeof(test2) / sizeof(int));
    Solution s;
    cout<<"[1, 2, 3, 4, 5]: "<<s.isStraight1(t0)<<endl;
    cout<<"[0, 0, 1, 2, 5]: "<<s.isStraight1(t1)<<endl;
    cout<<"[9, 10, 4, 0, 9]: "<<s.isStraight1(t2)<<endl;
    cout<<"[1, 2, 3, 4, 5]: "<<s.isStraight(t0)<<endl;
    cout<<"[0, 0, 1, 2, 5]: "<<s.isStraight(t1)<<endl;
    cout<<"[9, 10, 4, 0, 9]: "<<s.isStraight(t2)<<endl;
}