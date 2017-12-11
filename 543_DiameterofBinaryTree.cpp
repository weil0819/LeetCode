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
    /**
    * Idea: This problem is like nearest common ancestor problem
    * DFS(postOrder): we need to construct a recusive function which returns the depth of subtree
    * the path between two TreeNodes is the depth of left subtree + right subtree
    * 
    */
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    
    int height(TreeNode* node, int& diameter){
        if(node == NULL){
            return 0;
        }
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = max(diameter, leftHeight+rightHeight);
        return max(leftHeight, rightHeight)+1;
    }
};