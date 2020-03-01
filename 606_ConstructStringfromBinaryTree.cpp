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
    * Idea: preorder traversing: root->left->right
    * we should be aware that if one's right child is non-null, its left child should be ()
    * 
    */
    string tree2str(TreeNode* t) {
        string output= "";
        if(t == NULL){
            return output;
        }
        output.append(to_string(t->val));
        if(t->left){
            output.append("(");
            output.append(tree2str(t->left));
            output.append(")");
        }else if(t->left == NULL && t->right){
            output.append("()");
        }
        if(t->right){
            output.append("(");
            output.append(tree2str(t->right));
            output.append(")");            
        }
        return output;
        
    }
};