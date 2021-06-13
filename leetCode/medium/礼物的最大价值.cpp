/* 礼物的最大价值.cpp
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxValue(vector<vector<int> > &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int dp[m][n]; // 储存到grid[i][j]为止最大的值
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) // 初始值
                    dp[i][j] = grid[i][j];
                if (i == 0 && j) //只能向右👉
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                if (i && j == 0) //只能向下👇
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                if (i && j) // 向右👉或向下👇
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    Solution s;
    int t0[] = {1, 3, 1};
    int t1[] = {1, 5, 1};
    int t2[] = {4, 2, 1};
    vector<int> tt0(t0, t0 + sizeof(t0) / sizeof(int));
    vector<int> tt1(t1, t1 + sizeof(t1) / sizeof(int));
    vector<int> tt2(t2, t2 + sizeof(t2) / sizeof(int));
    vector<vector<int> > test;
    test.push_back(tt0);
    test.push_back(tt1);
    test.push_back(tt2);
    cout << s.maxValue(test) << endl; //12,  1→3→5→2→1
}