/*
Maximum Depth of Binary Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/

@date: May 8, 2020

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

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
    // DFS search
    // max depth = 1+ max(max left child, max right child)
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    // BFS search
    // Using queue to scan layer by layer
    /*
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int res = 0;
        queue<TreeNode*> helper;
        helper.push(root);
        
        while(!helper.empty()) {
            int N = helper.size();
            ++res;
            for(int i = 0; i < N; i++) {                
                TreeNode* node = helper.front();
                helper.pop();
                if(node->left) helper.push(node->left);
                if(node->right) helper.push(node->right);
            }
        }
        return res;
    }
    */
};


