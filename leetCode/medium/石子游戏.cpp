/* 石子游戏.cpp
亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 
这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。
示例：

输入：[5,3,4,5]
输出：true
解释：
亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        int dp[n][n];
        // [i][j]存储的是piles中第i个数到第j个数组成序列的最佳拿取方式下的得分
        //当集合中元素d等于1时，拿的那个人直接得分
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];
        //当集合中有两个数的时候，先选的人肯定是拿较大数,分数为max-min
        for (int i = 0; i < n - 1; i++)
            dp[i][i + 1] = abs(piles[i] - piles[i + 1]);
        /**当集合中元素大于2时，先选的人从序列两头拿，可以分成两种情况
        *以ABC为例，可以拿A，剩余BC，后手会选择BC的最佳拿取方式，
        *所以先手得分为A-BC得分，即：results[i][j]=piles[i]-results[i+1][j]；
        *也可以拿C，剩余AB，同理有results[i][j]=piles[j]-results[i][j-1]；
        *选择分值较大的那个即可。上面两个式子都要求我们在求results[i][j]的时候知道
        *它的下面和左边一个格子的值，所以我们从下到上，从左到右计算填表。
        */
        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
    bool stoneGame1(vector<int> &piles)
    {
        // 当piles.size()为偶数， 且共有奇数个石子时，先拿的人获胜。
        return true;
    }
};
int main()
{
    int t0[] = {5, 3, 4, 5};
    vector<int> t(t0, t0 + sizeof(t0) / sizeof(int));
    Solution s;
    cout << (s.stoneGame(t) ? "true" : "false") << endl; // true
    /* for the last question [5, 3, 4, 5]
        i=  0           1           2           3
    j=  0   5

        1  [5,3]        3
        [5,3]=2
        2  [5,3,4]      [3,4]       4
        [3,4]=1         
        [5,3,4]=max(5-dp([3,4]), 4-dp([5,3]))=max(5-1, 4-2)=4       
        3  [5,3,4,5]    [3,4,5]    [4,5]        5
        [4,5]=1     
        [3,4,5]=max(3-dp([4,5]), 5-dp(3,4))=max(3-1, 5-1)=4    
        [5,3,4,5]=max(5-dp([3,4,5]) - 5-dp([5,3,4]))=max(5-4, 5-4)=1
    dp[0][3] 亚历克斯是piles中第0个数到第piles.size()-1数组成序列 [5,3,4,5] 的最佳拿取方式下的得分
    >0 时 亚历克斯胜利
    */
}