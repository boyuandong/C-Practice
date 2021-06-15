/* 滑动窗口的最大值.cpp
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void printV(vector<int> v);
void printQ(deque<int> q);
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> empty_res;
        if (nums.empty())
            return empty_res;
        // vector<int> res(nums.size()-k+1,0);
        vector<int> res;
        deque<int> myQ;
        int low = (1 - k);
        int high = 0;
        int n = nums.size();
        while (low < n - k + 1 && high < n)
        {
            // printV(res);
            // printQ(myQ);
            // if the nums[low-1] just out of window and happends to be the last
            // greates number in the window, then drop it out of queue
            if (low > 0 && myQ.front() == nums[low - 1])
                myQ.pop_front();
            // when the highest pos number is now greater than the previos
            // add item in deque back(which is not the greatest), need to drop them all out
            while (!myQ.empty() && myQ.back() < nums[high])
                myQ.pop_back();
            // add the highest pos number now
            myQ.push_back(nums[high]);
            // push back the greates(front item in deque) into vector/list
            if (low >= 0)
                res.push_back(myQ.front());
            // res[low] = myQ.front();
            low += 1;
            high += 1;
        }
        return res;
    }
};
void printV(vector<int> v)
{
    if (v.empty())
    {
        cout << "vector: []" << endl;
        return;
    }
    int i;
    cout << "vector: [";
    for (i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[i] << "]" << endl;
}
void printQ(deque<int> q)
{
    if (q.empty())
    {
        cout << "queue: []" << endl;
        return;
    }
    cout << "queue: [";
    while (q.empty())
    {
        cout << q.front() << " ";
    }
    cout << "]" << endl;
}
int main()
{
    Solution s;
    int test0[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> v0 = s.maxSlidingWindow(t0, 3);
    printV(v0);
}