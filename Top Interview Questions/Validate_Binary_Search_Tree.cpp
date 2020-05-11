/*
Validate Binary Search Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/

@date: May 8, 2020

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

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
    // In-order traversal (DFS)    
    // Iterative Method: Stack, find the left-most one and then consider right child
    /*
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> helper;
        TreeNode* prev = NULL;
        while(root || !helper.empty()) {
            // first, push all left-brach children
            while(root) {
                helper.push(root);
                root = root->left;
            }
            // second, pop up the left-most leaf
            root = helper.top();
            helper.pop();
            
            // third, compare cur node with prev node
            if(prev && prev->val >= root->val) return false;
            prev = root;
            
            // four, push all right-branch children if they have left children
            root = root->right;
        }
        
        return true;
    }
    */
    
    // Recursive Method: InOrder(TreeNode*, vector<int>), from left->mid->right
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        // store node value in order traversal
        vector<int> nodeList;
        inOrder(root, nodeList);
        for(int i = 1; i < nodeList.size(); i++) {
            if(nodeList[i] <= nodeList[i-1]) return false;
        }
        return true;
    }
private:
    void inOrder(TreeNode* node, vector<int>& nodeList) {
        if(node->left) inOrder(node->left, nodeList);
        nodeList.push_back(node->val);
        if(node->right) inOrder(node->right, nodeList);
    }
};