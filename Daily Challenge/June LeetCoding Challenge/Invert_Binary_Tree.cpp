/*
Invert Binary Tree

@date: June 1, 2020

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Recursive method
    /*
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    */
    
    // Iterative method -- BFS -- queue<TreeNode*>
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            
            // push left & right
            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);
            
            // swap left and right
            swap(node->left, node->right);
        }
        return root;
    }
};