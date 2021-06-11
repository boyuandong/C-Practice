/* 矩阵中的路径.cpp
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        /*
        dfs + 回溯(backtracking)；
        使用二维布尔数组记录之前的位置是否已经被访问过，如果已经被访问过的话，则在 dfs 的过程中，直接 return false 即可。也就是说，此路已经不通了；
        如果当前遍历到的字符不等于 board[i][j] 位置上的字符，那么说明此路也是不通的，因此返回 false；
        至于递归结束的条件：如果指针 start 能够来到 word 的最后一个字符，那么说明能够在矩阵 board 中找到一条路径，此时返回 true；
        在遍历到当前 board[i][j] 的时候，首先应将该位置的 visited[i][j] 设置为 true，表明访问过；
        然后，递归地去 board[i][j] 的上下左右四个方向去找，剩下的路径；
在 dfs 的过程当中，如果某条路已经不通了，那么那么需要回溯，也就是将 visited[i][j] 位置的布尔值重新赋值为 fasle；
        最后，返回 ans 即可。
        */
        if (board.empty() || board[0].empty())
            return word.empty();
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (backtrack(board, row, col, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char> > &board, int row, int col, string word, int idx)
    {
        if (idx == word.size())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if (word[idx] != board[row][col])
            return false;

        board[row][col] = '*'; // no cycle
        if (backtrack(board, row - 1, col, word, idx + 1) || backtrack(board, row + 1, col, word, idx + 1) || backtrack(board, row, col - 1, word, idx + 1) || backtrack(board, row, col + 1, word, idx + 1))
            return true;

        board[row][col] = word[idx];
        return false;
    }
};