/* 和为s的两个数字.cpp
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        // 超出时间限制
        // time: O(N), space: O(N^2)
        int n1, n2;
        int i=0,j=1;
        int sum;
        while(sum != target)
        {
            n1 = nums[i];
            n2 = nums[j];
            sum = n1+n2;
            if(sum == target)
            {
                vector<int> ans;
                ans.push_back(n1);
                ans.push_back(n2);
                return ans;
            }
            if(j == nums.size()-1)
            {
                i++;
                j = i+1;
                continue;
            }
            j++;
        }
        vector<int> ans;
        return ans;
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
        // hash table
        // time: O(N), space: O(N)
        map<int, int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.count(target-nums[i]))
            {
                res.push_back(target - nums[i]);
                res.push_back(nums[i]);
                return res;
            }
            m[nums[i]] = nums[i];
        }
        return res;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        // 双指针
        // time: o(N), space: O(1)
        vector<int> res;
        int left=0, right=nums.size()-1;
        while(left<right)
        {
            int sum = nums[left] + nums[right];
            if(sum == target)
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                return res;
            }
            if(sum > target)
                right--;
            else
                left++;
        }
        return res;
    }
};