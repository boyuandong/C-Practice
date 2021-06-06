/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

 

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof
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
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric1(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode*root1, TreeNode*root2)
    {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        if(root1->val == root2->val)
        {
            return helper(root1->left, root2->right) && helper(root1->right, root2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;
        if(!root->left && !root->right) 
            return true;
        if(!root->left || !root->right) 
            return false;
        if(root->left->val != root->right->val)
            return false;
        swap(root->left->right, root->right->right);
        return isSymmetric(root->left) && isSymmetric(root->right);
    }
};

int main()
{}