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
    * Idea: 1.one recursion: 
    * define a help function which return the height of current TreeNode
    * we can adopt the postOrder traversal, and return the height of the current node in DFS recursion
    * When the sub tree of the current node (inclusive) is balanced, the function postOrder() returns a non-negative value as the height.         * Otherwise -1 is returned. According to the leftHeight and rightHeight of the two children, the parent node could check if the sub tree
    * is balanced, and decides its return value.
    *
    * 2.two recursions: 
    * define a recursion function which returns the height of current node,
    * and at the same time, we can recursively call isBalanced function to return: 
    * 1)the results of the height difference between left and right subtree; 
    * 2)whether left subtree is balanced; 
    * 3) whether right subtree is balanced
    *
    * Attention: Here, we regard the height of leaf is 1, NULL is 0
    * 
    */
    /*
    // Mehtod-I
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(postOrder(root) == -1){
            return false;
        }else{
            return true;
        }
    }
    int postOrder(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int leftH = postOrder(node->left);
        int rightH = postOrder(node->right);      
        //
        if(leftH == -1 || rightH == -1 && abs(leftH - rightH) > 1){
            return -1;
        }
        return max(leftH, rightH) + 1;
    }
    */
    // Method-II
    bool isBalanced(TreeNode* root){
        if(root == NULL){
            return true;
        }
        return abs(checkHeight(root->left)-checkHeight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int checkHeight(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        return max(checkHeight(node->left), checkHeight(node->right)) + 1;
    }
};