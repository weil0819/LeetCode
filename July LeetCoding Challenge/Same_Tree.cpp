/*
Same Tree

@date: July 13, 2020

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

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
    // BFS -- iterative
    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        
        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;
        
        Q1.push(p);
        Q2.push(q);
        
        while(!Q1.empty() && !Q2.empty()) {
            int N = Q1.size(), M = Q2.size();
            if(N != M) return false;
            for(int i = 0; i < N; i++) {
                TreeNode* t1 = Q1.front();
                TreeNode* t2 = Q2.front();
                Q1.pop(); Q2.pop();
                if(t1->val != t2->val) return false;
                if((t1->left != NULL && t2->left == NULL) || (t1->left == NULL && t2->left != NULL)) return false;
                if(t1->left) Q1.push(t1->left);
                if(t1->right) Q1.push(t1->right);
                if(t2->left) Q2.push(t2->left);
                if(t2->right) Q2.push(t2->right);
            }
        }
        
        if(!Q1.empty() || !Q2.empty()) return false;
        else return true;
    }*/
    
    // DFS -- recursive
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        else return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

