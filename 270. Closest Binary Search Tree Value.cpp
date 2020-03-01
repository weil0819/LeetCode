/*

270. Closest Binary Search Tree Value -- Easy
http://www.leetfree.com/problems/closest-binary-search-tree-value.html


Given a non-empty binary search tree and a target value, 
find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

*/

/*
问题：在BST中搜索与target最接近的值

从root开始比较，如果当前节点与target差值小于结果，那么就更新结果
如果root->val < target，那么搜索左子树root=root->left
否则，搜索右子树root=root->right

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

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;        // return value
        while(root != NULL) {
            if (abs(root->val - target) < abs(res - target)) {
                res = root->val;
            }
            if (root->val < target) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return res;
    }
};
