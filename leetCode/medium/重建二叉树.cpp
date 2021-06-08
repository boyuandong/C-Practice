/* 重建二叉树.cpp
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
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
#include<vector>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        /*
        C++题解，经典的建树，建树无论是前后建树，或者中后建树，要点都是传递中的序列下标，
        因为根结点下标都可以根据中进行推算。 我们直接返回build函数 在build中，如果start>end则返回是递归终止条件。
        我们将root节点new出来 然后while循环负责进行找到中节点中root节点的下标，最后左右递归即可。
        */
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int root, int start, int end)
    {
        // 中序的start和end
        if (start > end)
            return NULL;
        TreeNode *tree = new TreeNode(preorder[root]);
        int i = start;
        while (i < end && preorder[root] != inorder[i])
            i++;
        tree->left = build(preorder, inorder, root + 1, start, i - 1);
        tree->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);
        return tree;
    }
};