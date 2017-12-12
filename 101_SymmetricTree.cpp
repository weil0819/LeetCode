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
    * Idea: 1.BFS->iteratively
    * 2.recursively->auxiliary function
    * 
    */
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        //return checkSymmetric(root->left, root->right);
        return BFSUtil(root);
    }
    
    bool checkSymmetric(TreeNode* left, TreeNode* right){
        if(left == NULL && right != NULL){
            return false;
        }
        if(left != NULL && right == NULL){
            return false;
        }
        if(left == NULL && right == NULL){
            return true;
        }
        return (left->val == right->val) && checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
    
    bool BFSUtil(TreeNode* node){
        TreeNode* left;
        TreeNode* right;
        queue<TreeNode*> p;                     // p stores the left subtree
        queue<TreeNode*> q;                     // q stores the right subtree
        p.push(node->left);
        q.push(node->right);
        while(!p.empty() && !q.empty()){
            left = p.front();                   // left is the node in left subtree
            right = q.front();                  // right is the node in right subtree
            p.pop();
            q.pop();
            if(left == NULL && right == NULL){  // if both nodes are leaf, we consider the next node in BFS
                continue ;
            }
            if(left == NULL || right == NULL){
                return false;
            }
            if(left->val != right->val){
                return false;
            }
            p.push(left->left);                 // the order must be corresponded to each other
            q.push(right->right);               // that means, left->left <---> right->right AND left->right <---> right->left
            p.push(left->right);
            q.push(right->left);            
        }
        return true;
    }
    
};