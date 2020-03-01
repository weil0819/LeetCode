/*

124. Binary Tree Maximum Path Sum -- Hard
https://leetcode.com/problems/binary-tree-maximum-path-sum/

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting 
node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

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
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN; // initialize global variable
        
        maxPathDown(root);
        
        return maxValue;
    }
    
private:
    int maxValue;
    
    // parameter -- node should be the highest node of the maximum path
    // return value is max value of path extended from "node"
    int maxPathDown(TreeNode* node) {
        if(node == NULL) return 0;
        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));
        
        // the max path sum whose highest node is "node"
        maxValue = max(maxValue, left + node->val + right);
        
        return max(left, right) + node->val;
    }
};
