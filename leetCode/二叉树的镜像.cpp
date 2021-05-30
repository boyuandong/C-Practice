/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof
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
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* mirrorTree1(TreeNode* root) {
        // 递归
        // time: O(N), space: O(N)
        if(!root)
            return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree1(root->left);
        mirrorTree1(root->right);
        return root;
    }

    TreeNode* mirrorTree2(TreeNode* root) {
        // 迭代
        // stack 栈
        // The fastest method
        // time: O(N), space: O(N)
        stack<TreeNode*> sck;
        sck.push(root);
        while(!sck.empty())
        {
            TreeNode *temp = sck.top();
            sck.pop();
            if(!temp) 
                continue;
            swap(temp->left, temp->right);
            if(temp->right)
                sck.push(temp->right);
            if(temp->left)
                sck.push(temp->left);
        }
        return root;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        // 队列 queue
        // time: O(N), space: O(N)
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode * temp = que.front();
            que.pop();
            if(!temp)
                continue;
            swap(temp->left, temp->right);
            if(temp->left)
                que.push(temp->left);
            if(temp->right)
                que.push(temp->right);
        }
        return root;
    }
};

int main()
{

}