/*
顺时针打印矩阵.cpp
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int row=matrix.size(), col=matrix[0].size();
        if(!row ) return ans;
        if(!col ) return ans;
        // the edge index
        int left=0, top=0, right=col-1, bottom=row-1;
        while(1)
        {
            // -> left to right
            for(int i=left; i<=right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top > bottom)
                break;
            // top to bottom
            for(int i=top; i<=bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(right < left)
                break;
            // <- right to left
            for(int i=right; i>=left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(bottom < top)
                break;
            // bottom to top
            for(int i=bottom; i>=top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left > right)
                break;
        }

        return ans;
    }
};