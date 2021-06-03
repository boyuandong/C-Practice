/* 0～n-1中缺失的数字.cpp
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber1(vector<int>& nums) {
        int i=0;
        for(i=0; i<nums.size(); i++)
        {
            if(i!= nums[i])
                return i;
        }
        return i;
    }
    int missingNumber(vector<int>& nums) {
        // 二分法
        int low=0, high=nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == mid)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};
int main()
{
    Solution s;
    int t0[] = {0, 1, 3};
    vector<int> test0(t0, t0 + sizeof(t0) / sizeof(int));
    cout << s.missingNumber1(test0) << endl;
    cout << s.missingNumber(test0) << endl;
    int t1[] = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    vector<int> test1(t1, t1 + sizeof(t1) / sizeof(int));
    cout << s.missingNumber1(test1) << endl;
    cout << s.missingNumber(test1) << endl;
}