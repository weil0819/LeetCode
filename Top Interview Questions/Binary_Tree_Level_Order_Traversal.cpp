/*
Binary Tree Level Order Traversal
https://leetcode.com/explore/featured/card/top-interview-questions-easy/94/trees/628/

@date: May 11, 2020

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    // Iterative method -- BFS -- queue<TreeNode*>
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        queue<TreeNode*> helper;
        helper.push(root);
        while(!helper.empty()) {
            int N = helper.size();
            vector<int> tmp;
            for(int i = 0; i < N; i++) {
                TreeNode* node = helper.front();
                tmp.push_back(node->val);
                helper.pop();
                if(node->left) helper.push(node->left);
                if(node->right) helper.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
    */
    
    // Recursive method -- DFS -- pre-order traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        DFSUtil(res, root, 0);
        return res;
    }
    
private:
    void DFSUtil(vector<vector<int> >& res, TreeNode* node, int depth) {
        if(node == NULL) return ;
        if(depth >= res.size()) res.push_back(vector<int>());
        res[depth].push_back(node->val);
        DFSUtil(res, node->left, depth+1);
        DFSUtil(res, node->right, depth+1);
    }
};