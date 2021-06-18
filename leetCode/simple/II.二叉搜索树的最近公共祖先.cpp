/* II.二叉搜索树的最近公共祖先.cpp
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof
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
private:
    vector<TreeNode *> getPath(TreeNode *root, TreeNode *target)
    {
        vector<TreeNode *> path;
        if (!root)
            return path;
        TreeNode *node = root;
        while (node->val != target->val)
        {
            path.push_back(node);
            if (target->val < node->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }

public:
    TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 两次遍历 time O(N), space O(N)
        /*
        分别得到了从根节点到 p 和 q 的路径之后，我们就可以很方便地找到它们的最近公共祖先了。
        显然，p 和 q 的最近公共祖先就是从根节点到它们路径上的「分岔点」，也就是最后一个相同的节点。
        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-0wpw1/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        */
        vector<TreeNode *> path_p = getPath(root, p);
        vector<TreeNode *> path_q = getPath(root, q);
        TreeNode *ancestor;
        for (int i = 0, j = 0; i < path_p.size() && j < path_q.size(); i++, j++)
        {
            if (path_p[i] == path_q[j])
                ancestor = path_p[i];
            else
                break;
        }
        return ancestor;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 一次遍历 time O(N), space O(1)
        /*
        我们从根节点开始遍历；
        1. 如果当前节点的值大于 p 和 q 的值，说明 p 和 q 应该在当前节点的左子树，因此将当前节点移动到它的左子节点；
        2. 如果当前节点的值小于 p 和 q 的值，说明 p 和 q 应该在当前节点的右子树，因此将当前节点移动到它的右子节点；
        3. 如果当前节点的值不满足上述两条要求，那么说明当前节点就是「分岔点」。此时，p 和 q 要么在当前节点的不同的子树中，要么其中一个就是当前节点。
        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-0wpw1/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        */
        if (!root)
            return root;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);
    root1->left->right->left = new TreeNode(3);
    root1->left->right->right = new TreeNode(5);
    TreeNode *node_p = new TreeNode(2);
    TreeNode *node_q = new TreeNode(8);
    TreeNode *res1 = s.lowestCommonAncestor1(root1, node_p, node_q);
    TreeNode *res2 = s.lowestCommonAncestor(root1, node_p, node_q);
    cout << (res1->val) << endl; // 6
    cout << (res2->val) << endl; // 6
    cout << endl;
    node_q->val = 4;
    cout << s.lowestCommonAncestor1(root1, node_p, node_q)->val << endl; // 2
    cout << s.lowestCommonAncestor(root1, node_p, node_q)->val << endl;  // 2
    cout << endl;
    TreeNode *root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    node_p->val = 2;
    node_q->val = 3;
    cout << s.lowestCommonAncestor1(root2, node_p, node_q)->val << endl; // 2
    cout << s.lowestCommonAncestor(root2, node_p, node_q)->val << endl;  // 2
    cout << endl;
    root2->left = new TreeNode(1);
    node_p->val = 3;
    node_q->val = 1;
    cout << s.lowestCommonAncestor1(root2, node_p, node_q)->val << endl; // 2
    cout << s.lowestCommonAncestor(root2, node_p, node_q)->val << endl;  // 2
    cout << endl;
    TreeNode *root3 = new TreeNode(3);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(4);
    root3->left->right = new TreeNode(2);
    node_p->val = 2;
    node_q->val = 3;
    cout << s.lowestCommonAncestor1(root3, node_p, node_q)->val << endl; // 3
    cout << s.lowestCommonAncestor(root3, node_p, node_q)->val << endl;  // 3
}