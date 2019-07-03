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
    * Idea: inOrder traversal can get an ordered sequence
    * we should record the val in the previous element and current minimum difference
    * Here, we constrcut a inorder function with TreeNode, previous element and minimum difference as parameters
    * 
    */
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int pre = -1, minDif = INT_MAX;
        inOrder(root, pre, minDif);
        return minDif;
    }
    
    void inOrder(TreeNode* root, int& pre, int& minDif){
        if(root->left){
            inOrder(root->left, pre, minDif);
        }
        if(pre >= 0){
            minDif = min(root->val-pre, minDif);
        }        
        pre = root->val;
        if(root->right){
            inOrder(root->right, pre, minDif);
        }        
    }
};