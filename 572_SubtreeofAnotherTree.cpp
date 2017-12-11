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
    * Idea: tree traversal
    * We need to construct a recursive function to decide whether the subtrees with current nodes as roots are same
    * If t is same as s, return true; 
    * if not, we need to traverse s->left and s->right to find whether t is substree of s->left and s->right
    * 
    */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL){
            return false;
        }
        if(isSame(s, t)){
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSame(TreeNode* s, TreeNode* t){
        if(s == NULL && t == NULL){
            return true;
        }
        if(s == NULL || t == NULL){
            return false;
        }
        if(s->val != t->val){
            return false;
        }else{              // if s == t, s->left must == t->left, and s->right must == t->right
            return isSame(s->left, t->left) && isSame(s->right, t->right);
        }        
    }
};