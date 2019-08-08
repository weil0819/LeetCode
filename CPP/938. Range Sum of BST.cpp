/*

938. Range Sum of BST -- Easy 
https://leetcode.com/problems/range-sum-of-bst/ 

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23
 

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.

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
	// Method-I:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL) return 0;
        int res = 0;
        // Case-I: root is between L and R, root should be included
        if(root->val >= L && root->val <= R) res += root->val;
        // Case-II: root is larger than L, find left child
        if(root->val > L) res += rangeSumBST(root->left, L, R);
        // Case-III: root is less than R, find right child
        if(root->val < R) res += rangeSumBST(root->right, L, R);
        
        return res;        
    }

    // Method-II:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL) return 0;
        
        int res = 0;
        stack<TreeNode*> S;
        S.push(root);
        
        while(!S.empty()) {
            TreeNode* node = S.top();
            S.pop();
            
            if(node->val >= L && node->val <= R) res += node->val;
            if(node->val > L && node->left) S.push(node->left);
            if(node->val < R && node->right) S.push(node->right);
        }
        return res;
    }
};



