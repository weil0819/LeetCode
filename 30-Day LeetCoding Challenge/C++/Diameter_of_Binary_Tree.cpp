/*
Diameter of Binary Tree
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3293/

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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
    // Recursion
    // diameter = max{height of left + height of right + 1, left diameter, right diameter}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
            
        return max(leftHeight+rightHeight, max(leftDiameter, rightDiameter));
    }
    
private:
    int getHeight(TreeNode* node) {
        if(node == NULL) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};


