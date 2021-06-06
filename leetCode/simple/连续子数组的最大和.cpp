/* 连续子数组的最大和.cpp
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
        int sum=nums[0];
        int max_sum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(sum <= 0)
                sum = nums[i];
            else
                sum += nums[i];
            if(max_sum < sum)
            {
                max_sum = sum;
            }
        }
        return max_sum;
    }
    int maxSubArray(vector<int>& nums) {
        // 动态规划
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        int max_sum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            sum[i] = max(sum[i-1]+nums[i], nums[i]);
            max_sum = max(max_sum, sum[i]);
        }
        return max_sum;
    }
};