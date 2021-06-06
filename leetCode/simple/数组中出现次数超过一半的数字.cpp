/* 数组中出现次数超过一半的数字.cpp
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        // 解法一： 建立哈希表法 HashTable
        // time: O(N), space: O(N/2)
        map<int, int> myMap;
        int count = nums.size()/2;
        for(int i=0; i<nums.size(); i++)
        {
            myMap[nums[i]]++;
        }
        map<int,int>::iterator it;
        for(it=myMap.begin(); it!=myMap.end(); ++it)
        {
            if(it->second > count)
                return it->first;
        }
        return -1;
    }
    int majorityElement2(vector<int>& nums) {
        // 解法二： 排序取中位数
        // time: O(NlogN), space: O(1)
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
    int majorityElement(vector<int>& nums) {
        //解法三：摩尔投票法
        //也可以理解成混战极限一换一，不同的两者一旦遇见就同归于尽，
        // 最后活下来的值都是相同的，即要求的结果
        //time: O(N)，space: O(1)
        int n=0, count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count == 0)
            {
                n = nums[i];
                count++;
            }
            else
            {
                if(n==nums[i])
                    count++;
                else
                    count--;
            }
        }
        return n;
    }
    
};