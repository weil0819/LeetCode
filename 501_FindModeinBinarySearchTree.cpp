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
    * Idea: we can get a sorted sequence with duplicated elements by using inOrder traversal
    * 
    */
    vector<int> findMode(TreeNode* root) {
        vector<int> output;
        if(root == NULL){
            return output;
        }
        
        int maxFre = 0, count = 0, pre = INT_MIN; 
        inOrder(root, pre, count, maxFre);     
        inOrder(root, pre, count, maxFre, output);
        
        return output;
    }
    void inOrder(TreeNode* node, int& pre, int& count, int& maxFre){    //If the parameters need to update, we should use &
        if(node->left){
            inOrder(node->left, pre, count, maxFre);
        }              
        if(node->val == pre){
            ++count;
        }else{            
            count = 1;
            pre = node->val;
        }
        maxFre = max(count, maxFre);
        if(node->right){
            inOrder(node->right, pre, count, maxFre);
        }
    }
    
    void inOrder(TreeNode* node, int& pre, int& count, int maxFre, vector<int>& output){
        if(node->left){
            inOrder(node->left, pre, count, maxFre, output);
        }
        if(node->val == pre){
            ++count;
        }else{
            if(count == maxFre){
                output.push_back(pre);
            }
            count = 1;
            pre = node->val;
        }
        
        if(node->right){
            inOrder(node->right, pre, count, maxFre, output);
        }
    }
};