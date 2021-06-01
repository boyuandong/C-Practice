/* 从上到下打印二叉树II.cpp

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof
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
#include<queue>
using namesapce std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS
        // 一个队列 queue
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        while(!treeQ.empty())
        {
            vector<int> level;
            int size = treeQ.size();
            while(size)
            {
                TreeNode* node = treeQ.front();
                if(node->left) treeQ.push(node->left);
                if(node->right) treeQ.push(node->right);
                level.push_back(node->val);
                treeQ.pop();
                size--;
            }
            res.push_back(level);
        }
        return res;
    }
};