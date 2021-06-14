/* I.数组中数字出现的次数.cpp
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> singleNumbers1(vector<int> &nums)
    {
        // using the map
        // slow
        map<int, int> Mymap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            Mymap[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (Mymap[nums[i]] == 1)
                res.push_back(nums[i]);
        }
        return res;
    }
    vector<int> singleNumbers(vector<int> &nums)
    {
        // 假设两个不同值为ab表示
        // 根据异或的规则，相同为0不同为1，且a^0 = a。那么遍历异或整个数组。
        // 最后的值就是a^b（因为其他被削掉了）
        // 再对整个数组进行拆分 把a放到一个数组1 b放到另一个数组2中；
        // 再分别对数组1、数组2遍历异或，最后的值就是结果值；
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum ^= nums[i];
        }
        //得到sum的二进制的1的最低位
        int flag = (-sum) & sum;
        vector<int> res(2, 0);
        //分成两个组进行异或，每组异或后的结果就是不相同两个数的其中之一
        for (int i = 0; i < nums.size(); i++)
        {
            if ((flag & nums[i]) == 0)
                res[0] ^= nums[i];
            else
                res[1] ^= nums[i];
        }
        return res;
    }
};
void printV(vector<int> v)
{
    int i;
    cout << "[";
    for (i = 0; i < v.size() - 1; i++)
        cout << v[i] << ", ";
    cout << v[i] << "]" << endl;
}
int main()
{
    Solution s;
    int test0[] = {4, 1, 4, 6};
    int test1[] = {1, 2, 10, 4, 1, 4, 3, 3};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    vector<int> v0 = s.singleNumbers1(t0);
    vector<int> v1 = s.singleNumbers1(t1);
    printV(v0); // [1,6]
    printV(v1); // [2,10]
    vector<int> v2 = s.singleNumbers(t0);
    vector<int> v3 = s.singleNumbers1(t1);
    printV(v2); // [1,6]
    printV(v3); // [2,10]
}