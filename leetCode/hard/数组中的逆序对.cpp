/* 数组中的逆序对.cpp
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
示例 1:

输入: [7,5,6,4]
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int reversePairs1(vector<int> &nums)
    {
        // 超时
        if (nums.empty() || nums.size() < 2)
            return 0;
        int i = 0, j = 1;
        int count = 0;
        while (i < nums.size())
        {
            if (nums[i] > nums[j])
            {
                count++;
                j++;
            }
            if (j == nums.size() - 1)
            {
                i++;
                j = i + 1;
            }
        }
        return count;
    }
    int reversePairs(vector<int> &nums)
    {
        // merge sort
        if (nums.empty() || nums.size() < 2)
            return 0;
        // int count = 0;
        vector<int> temp(nums.size(), 0);
        return mergeSort_reversePairs(nums, 0, nums.size() - 1, temp);
        // return count;
    }

private:
    int mergeSort_reversePairs(vector<int> &nums, int l, int r, vector<int> &temp)
    {
        // 在数组 nums 的区间 [left, right] 统计逆序
        if (l == r)
            return 0;
        int m = (l + r) / 2;
        int left_count = mergeSort_reversePairs(nums, l, m, temp);
        int right_count = mergeSort_reversePairs(nums, m + 1, r, temp);
        int reverse_pairs = left_count + right_count;
        // 代码走到这里的时候，[left, mid] 和 [mid + 1, right] 已经完成了排序并且计算好逆序对
        if (nums[m] <= nums[m + 1]) //此时不用计算横跨两个区间的逆序对，直接返回 reverse_pairs
            return reverse_pairs;
        int reverse_cross_pairs = merge(nums, l, m, r, temp);
        return reverse_pairs + reverse_cross_pairs;
    }
    int merge(vector<int> nums, int l, int m, int r, vector<int> &temp)
    {
        /*
        [left, mid] 有序，[mid + 1, right] 有序

        前：[2, 3, 5, 8]，后：[4, 6, 7, 12]
        只在后面数组元素出列的时候，数一数前面这个数组还剩下多少个数字，
        由于"前"数组和"后"数组都有序，
        此时"前"数组剩下的元素个数 mid - i + 1 就是与"后"数组元素出列的这个元素构成的逆序对个数

        作者：liweiwei1419
        链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/bao-li-jie-fa-fen-zhi-si-xiang-shu-zhuang-shu-zu-b/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        */
        for (int i = l; i < r + 1; i++)
            temp[i] = nums[i];

        int i = l;
        int j = m + 1;
        int res = 0;
        for (int k = l; k < r + 1; k++)
        {
            if (i > m)
            {
                nums[k] = temp[j];
                j++;
            }
            else if (j > r)
            {
                nums[k] = temp[i];
                i++;

                // res += (r - m);
            }
            else if (temp[i] <= temp[j])
            {
                nums[k] = temp[i];
                i++;

                // res += (j-m - 1);
            }
            else
            {
                // assert(temp[i] > temp[j]);
                nums[k] = temp[j];
                j++;
                res += (m - i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int test0[] = {7, 5, 6, 4};
    int test1[] = {3, 2, 1};
    int test2[] = {4, 5, 6, 7};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    vector<int> t2(test2, test2 + sizeof(test2) / sizeof(int));
    cout << s.reversePairs(t0) << endl; // 5
    cout << s.reversePairs(t1) << endl; // 3
    cout << s.reversePairs(t2) << endl; // 0
}