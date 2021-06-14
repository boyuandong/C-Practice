/* 构建乘积数组.cpp
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> constructArr1(vector<int> &a)
    {
        // 超出时间限制
        // time: O(N^2), space: O(N)
        vector<int> res;
        if (a.empty())
            return res;
        for (int i = 0; i < a.size(); i++)
        {
            int product = 1;
            for (int j = 0; j < a.size(); j++)
            {
                if (i != j)
                    product *= a[j];
            }
            res.push_back(product);
        }
        return res;
    }
    vector<int> constructArr(vector<int> &a)
    {
        // time: O(N), space: O(N)
        vector<int> res(a.size(), 0);
        if (a.empty())
            return res;
        // 先乘左边的数(不包括自己)
        for (int i = 0, product = 1; i < a.size(); i++)
        {
            res[i] = product;
            product *= a[i];
        }
        // 再乘右边的数(不包括自己)
        for (int i = a.size() - 1, product = 1; i >= 0; i--)
        {
            res[i] *= product;
            product *= a[i];
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
    int test0[] = {1, 2, 3, 4, 5};
    int test1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    // [120, 60, 40, 30, 24]
    vector<int> v0 = s.constructArr1(t0);
    vector<int> v1 = s.constructArr(t0);
    printV(v0);
    printV(v1);
    // vector<int> v2 = s.constructArr1(t1); // run overtime
    vector<int> v3 = s.constructArr(t1);
    printV(v3);
}