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
    * Idea: Since it requires level order, we can consider the BFS method
    * use a stack to record the vector from up to bottom
    * 
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > output;
        if(root == NULL){
            return output;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> res;
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front();
                q.pop();
                res.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            output.push_back(res);
        }
        reverse(output.begin(), output.end());
        return output;
    }
    
    
};