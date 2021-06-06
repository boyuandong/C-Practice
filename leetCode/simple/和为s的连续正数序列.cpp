/* 和为s的连续正数序列.cpp
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int> > findContinuousSequence(int target)
    {
        // 双指针
        vector<vector<int> > res;
        int left = 1, right = 2;
        int sum = 0;
        while (left < right)
        {
            vector<int> ans;
            sum = (left + right) * (right - left + 1) / 2;
            if (sum == target)
            {
                for (int i = left; i <= right; i++)
                    ans.push_back(i);
                res.push_back(ans);
                left++;
                right++;
            }
            if (sum > target)
                left++;
            if (sum < target)
                right++;
        }
        return res;
    }
};
void printVecint(vector<int> v)
{
    int i;
    cout << "[";
    for (i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[i] << "] ";
}
void printVecv(vector<vector<int> > allv)
{
    int i;
    cout << "[";
    for (i = 0; i < allv.size(); i++)
    {
        printVecint(allv[i]);
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<vector<int> > test0 = s.findContinuousSequence(3);
    printVecv(test0);
    vector<vector<int> > test1 = s.findContinuousSequence(9);
    printVecv(test1);
    vector<vector<int> > test2 = s.findContinuousSequence(15);
    printVecv(test2);
}