/* 在排序数组中查找数字I.cpp
统计一个数字在排序数组中出现的次数。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int search1(vector<int>& nums, int target) {
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == target)
                count++;
            if(nums[i] > target)
                return count;
        }
        return count;
    }
    int search(vector<int>& nums, int target) {
            // 二分法
            int low=0, high=nums.size()-1;
            int count=0;
            while(low<high)
            {
                int mid=(low+high)/2;
                if(nums[mid]>=target)
                    high = mid;
                if(nums[mid]<target)
                    low = mid+1;
            }
            while(low<nums.size() && nums[low++]==target)
                count++;
            return count;
    }
};