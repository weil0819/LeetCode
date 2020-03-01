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
    * Idea: If a TreeNode is a left-leaf, we sum its val; if it is a right-leaf, we sum 0
    * we need to construct a recusive function, based on taht, we can sum the left and right results 
    * Attention: Breadth First Traversal == Level Order Traversal
    *            Depth First Traversals == Inorder Traversal (Left-Root-Right)
    *                                      Preorder Traversal (Root-Left-Right)
    *                                      Postorder Traversal (Left-Right-Root)   
    */
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }    
};
