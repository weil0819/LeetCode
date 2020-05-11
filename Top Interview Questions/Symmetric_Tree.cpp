/*
Symmetric Tree
https://leetcode.com/explore/featured/card/top-interview-questions-easy/94/trees/627/

@date: May 11, 2020

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

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
    // Recursive method: compare left and right child in each round
    /*
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return checkSymmetric(root->left, root->right);
    }
private:
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if(left == NULL && right) return false;
        if(left && right == NULL) return false;
        if(left == NULL && right == NULL) return true;
        return (left->val == right->val) && checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
    */
    
    // Iterative method: BFS search -- two queue
    bool isSymmetric(TreeNode* root) {
        TreeNode* left;
        TreeNode* right;
        
        if(root == NULL) return true;
        
        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;
        Q1.push(root->left);
        Q2.push(root->right);
        
        while(!Q1.empty() && !Q2.empty()) {
            left = Q1.front();
            right = Q2.front();
            Q1.pop();
            Q2.pop();
            
            if(left == NULL && right == NULL) continue ;
            if(left == NULL || right == NULL) return false;
            if(left->val != right->val) return false;
            
            // for left, push left child first, i.e., from left to right
            Q1.push(left->left);
            Q1.push(left->right);
            // for right, push right child first, i.e., from right to left
            Q2.push(right->right);
            Q2.push(right->left);
        }
        return true;
    }
};
