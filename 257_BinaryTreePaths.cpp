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
    * Idea: DFS, we can consider preOrder traversal method to visit the root, left and right subtree
    * 
    */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        if(root == NULL){
            return output;
        }
        string path = "";        
        preOrder(root, path, output);
        return output;
    }
    void preOrder(TreeNode* node, string path, vector<string>& output){        
        if(node->left == NULL && node->right == NULL){  
            path = path + to_string(node->val);
            output.push_back(path);
        }
        if(node->left){
            preOrder(node->left, path + to_string(node->val) + "->", output);
        }
        if(node->right){
            preOrder(node->right, path + to_string(node->val) + "->", output);
        }            
    }
};