/* 机器人的运动范围.cpp
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
using namespace std;
class Solution
{
    int vis[101][101] = {0};

public:
    int movingCount(int m, int n, int k)
    {
        // dfs
        if (k == 0)
            return 1;
        return dfs(0, 0, m, n, k);
    }
    int dfs(int x, int y, int m, int n, int k)
    {
        if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] || sum(x, y) > k)
            return false;
        vis[x][y] = 1;
        int up = dfs(x - 1, y, m, n, k);
        int bottom = dfs(x + 1, y, m, n, k);
        int left = dfs(x, y - 1, m, n, k);
        int right = dfs(x, y + 1, m, n, k);
        return up + bottom + left + right + 1;
    }
    int sum(int x, int y)
    {
        int res = 0;
        while (x)
        {
            res += x % 10;
            x /= 10;
        }
        while (y)
        {
            res += y % 10;
            y /= 10;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl; // 3
    cout << s.movingCount(3, 1, 0) << endl; // 1
}