/* 股票的最大利润.cpp
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit1(vector<int> &prices)
    {
        // 动态规划
        if (prices.empty())
            return 0;
        vector<int> dp(prices.size(), 0);
        int buy = prices[0], sale = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
                sale = buy;
            }
            if (prices[i] > sale)
            {
                sale = prices[i];
            }
            dp[i] = max(sale - buy, dp[i - 1]);
        }
        return dp[prices.size() - 1];
    }
    int maxProfit(vector<int> &prices)
    {
        // 遍历数组
        if (prices.empty())
            return 0;
        int buy = prices[0];
        int res = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            else
                res = max(res, prices[i] - buy);
        }
        return res;
    }
};
int main()
{
    Solution s;
    int test0[] = {7, 1, 5, 3, 6, 4};
    int test1[] = {7, 6, 4, 3, 1};
    vector<int> t0(test0, test0 + sizeof(test0) / sizeof(int));
    vector<int> t1(test1, test1 + sizeof(test1) / sizeof(int));
    cout << s.maxProfit1(t0) << endl; //5
    cout << s.maxProfit(t0) << endl;  //5
    cout << s.maxProfit1(t1) << endl; //0
    cout << s.maxProfit(t1) << endl;  //0
    vector<int> t;
    cout << s.maxProfit1(t) << endl; //0
    cout << s.maxProfit(t) << endl;  //0
}