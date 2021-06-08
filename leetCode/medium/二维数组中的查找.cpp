/* 二维数组中的查找.cpp
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int> > &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        if (matrix[0][0] > target)
            return false;
        if (matrix[n][m] < target)
            return false;
        int row = 0, col = m;
        while (row <= n && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] > target)
                col--;
            else if (matrix[row][col] < target)
                row++;
        }
        return false;
    }
};
int main()
{
    Solution s;
    int m_0[] = {1, 4, 7, 11, 15};
    int m_1[] = {2, 5, 8, 12, 19};
    int m_2[] = {3, 6, 9, 16, 22};
    int m_3[] = {10, 13, 14, 17, 24};
    int m_4[] = {18, 21, 23, 26, 30};
    vector<int> t0(m_0, m_0 + sizeof(m_0) / sizeof(int));
    vector<int> t1(m_1, m_1 + sizeof(m_1) / sizeof(int));
    vector<int> t2(m_2, m_2 + sizeof(m_2) / sizeof(int));
    vector<int> t3(m_3, m_3 + sizeof(m_3) / sizeof(int));
    vector<int> t4(m_4, m_4 + sizeof(m_4) / sizeof(int));
    vector<vector<int> > test0;
    test0.push_back(t0);
    test0.push_back(t1);
    test0.push_back(t2);
    test0.push_back(t3);
    test0.push_back(t4);
    cout << (s.findNumberIn2DArray(test0, 5) ? "true" : "false") << endl;  // true
    cout << (s.findNumberIn2DArray(test0, 20) ? "true" : "false") << endl; // false

    vector<vector<int> > test1;
    cout << (s.findNumberIn2DArray(test1, 1) ? "true" : "false") << endl; // false

    vector<vector<int> > test2;
    test2.push_back(vector<int>(1, 1));
    test2.push_back(vector<int>(1, 3));
    test2.push_back(vector<int>(1, 5));
    cout << (s.findNumberIn2DArray(test2, 1) ? "true" : "false") << endl; // true
    cout << (s.findNumberIn2DArray(test2, 2) ? "true" : "false") << endl; // false
}