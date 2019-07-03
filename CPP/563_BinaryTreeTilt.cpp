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
    * Idea: Since we need to calculate the difference between left and right, we can consider the postOrder traversal
    * left->right->root
    * We construct a function with parameter difSum which counts the difference between two subtree
    * and return the sum of left and right subtree
    */
    int findTilt(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int difSum = 0;
        postOrder(root, difSum);
        return difSum;
    }
    int postOrder(TreeNode* root, int& difSum){
        int leftSum = 0, rightSum = 0;
        if(root->left){
            leftSum = postOrder(root->left, difSum);
        }
        if(root->right){
            rightSum = postOrder(root->right, difSum);
        }
        difSum += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};