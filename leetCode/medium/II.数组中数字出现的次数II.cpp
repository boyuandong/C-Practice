/* II.数组中数字出现的次数II.cpp
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber1(vector<int> &nums)
    {
        // map 解法
        map<int, int> Mymap;
        for (int i = 0; i < nums.size(); i++)
            Mymap[nums[i]]++;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Mymap[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }
    int singleNumber(vector<int> &nums)
    {
        // 二进制解法
        /*
        如果一个数字出现3次，它的二进制每一位也出现的3次。如果把所有的出现三次的数字的二进制表示的每一位都分别加起来，
        那么每一位都能被3整除。 我们把数组中所有的数字的二进制表示的每一位都加起来。
        如果某一位能被3整除，那么这一位对只出现一次的那个数的这一肯定为0。
        如果某一位不能被3整除，那么只出现一次的那个数字的该位置一定为1.
        */
        vector<int> k(32, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 32; j++)
            {
                k[j] += (nums[i] >> j & 1) == 1 ? 1 : 0;
            }
        }
        int res = 0;
        for (int i = 31; i >= 0; i--)
        {
            res = res << 1;
            if (k[i] % 3 == 1)
                res = (res | 1);
        }
        return res;
    }
};
int main()
{
    Solution s;
    int test0[] = {3, 4, 3, 3};
    int test1[] = {9, 1, 7, 9, 7, 9, 7};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    cout << s.singleNumber1(t0) << endl; //4
    cout << s.singleNumber(t0) << endl;  //4
    cout << s.singleNumber1(t1) << endl; //1
    cout << s.singleNumber(t1) << endl;  //1
}