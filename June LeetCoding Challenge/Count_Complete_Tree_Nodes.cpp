/*
Count Complete Tree Nodes

@date: June 23, 2020

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

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
    // Method-I: BFS scan each layer
    /*
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> Q;
        Q.push(root);
        int res = 0;
        
        while(!Q.empty()) {
            int N = Q.size();
            res += N;
            for(int i = 0; i < N; i++) {
                TreeNode* t = Q.front();
                Q.pop();
                if(t->left) Q.push(t->left);
                if(t->right) Q.push(t->right);
            }
        }
        return res;
    }
    */
    
    // Method-II: 
    int countNodes(TreeNode* root) {
        int res = 0, h = height(root);
        while(root) {
            if(height(root->right) == h-1) {
                res += 1<<h;
                root = root->right;
            } else {
                res += 1<<(h-1);
                root = root->left;
            }
            h--;
        }
        return res;
    }
private: 
    int height(TreeNode* root) {
        return root == NULL ? -1 : 1+height(root->left);
    }
};

