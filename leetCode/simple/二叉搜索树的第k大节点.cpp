/* 二叉搜索树的第k大节点.cpp
给定一棵二叉搜索树，请找出其中第k大的节点。
示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int kthLargest1(TreeNode *root, int k)
    {
        vector<int> l;
        dfs1(root, l);
        return l[l.size() - k];
    }

    void dfs1(TreeNode *root, vector<int> &l)
    {
        if (!root)
            return;
        if (root->left)
            dfs1(root->left, l);
        l.push_back(root->val);
        if (root->right)
            dfs1(root->right, l);
    }
    // method 2:
    int ans = 0, count = 0;
    int kthLargest(TreeNode *root, int k)
    {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode *root, int k)
    {
        if (!root)
            return;
        if (root->right)
            dfs(root->right, k);
        if (++count == k)
        {
            ans = root->val;
            return;
        }
        if (root->left)
            dfs(root->left, k);
    }
};