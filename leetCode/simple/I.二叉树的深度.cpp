/* I.二叉树的深度.cpp
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof
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
#include <queue>
#include <cmath>
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
    int maxDepth1(TreeNode *root)
    {
        // recursive
        // 后序遍历（DFS）
        // time O(N), space O(N)
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int maxDepth(TreeNode *root)
    {
        // 层序遍历（BFS）
        // time O(N), space O(N)
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            queue<TreeNode *> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *r = q.front();
                q.pop();
                if (r->left)
                    temp.push(r->left);
                if (r->right)
                    temp.push(r->right);
            }
            q = temp;
            res++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.maxDepth1(root) << endl; //3
    cout << s.maxDepth(root) << endl;  //3
}