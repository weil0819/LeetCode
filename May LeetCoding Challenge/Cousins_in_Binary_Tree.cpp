/*
Cousins in Binary Tree

@date: May 7, 2020

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

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
    // BFS to scan the tree layer by layer
    // queue<TreeNode*>
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        queue<TreeNode*> helper;
        helper.push(root);
        
        while(!helper.empty()) {
            int N = helper.size();
            bool xExists = false, yExists = false;
            while(N--) {
                TreeNode* tmp = helper.front();
                helper.pop();
                if(tmp->val == x) xExists = true;
                if(tmp->val == y) yExists = true;
                if(tmp->left && tmp->right) {
                    // different parent
                    if((tmp->left->val == x && tmp->right->val == y) || 
                       (tmp->left->val == y && tmp->right->val == x)) {
                        return false;
                    }
                }                
                
                if(tmp->left) helper.push(tmp->left);
                if(tmp->right) helper.push(tmp->right);
            }
            if(xExists && yExists) return true;
            else if(xExists || yExists) return false;
        }
        return false;
    }
};


