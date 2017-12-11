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
private:
    int sum = 0;
    
public:
    /**
    * Idea: firstly we must handle the last one in inOrder traversal result which is the largeest one
    * Thus, if TreeNode has right child, we should continue to compute its right child until it is NULL
    * then, we get root, further we deal with left child
    * This idea just likes a inOrder traversal but it firstly consider the right child, then root, further left child
    * 
    */
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        if(root->right){
            convertBST(root->right);
        }
        sum += root->val;
        root->val = sum;
        if(root->left){
            convertBST(root->left);
        }
        return root;
    }

};