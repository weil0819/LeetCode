/*
Binary Tree Level Order Traversal II

@date: July 2, 2020

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    // BFS up-bottom level and then reverse
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            int n = Q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                TreeNode* t = Q.front();
                Q.pop();
                temp.push_back(t->val);
                if(t->left) Q.push(t->left);
                if(t->right) Q.push(t->right);
            }
            res.push_back(temp);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

