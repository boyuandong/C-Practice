/* II.平衡二叉树.cpp
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
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
#include <queue>
#include <iostream>
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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int maxDepth1(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            queue<TreeNode *> temp;
            int n = q.size();
            for (int i = 0; i < n; i++)
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
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout << (s.isBalanced(root1) ? "True" : "False") << endl; // true
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);
    cout << (s.isBalanced(root2) ? "True" : "False") << endl; // false
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(2);
    root3->left->left = new TreeNode(3);
    root3->right->right = new TreeNode(3);
    root3->left->left->left = new TreeNode(4);
    root3->right->right->right = new TreeNode(4);
    cout << (s.isBalanced(root3) ? "True" : "False") << endl; //false
}