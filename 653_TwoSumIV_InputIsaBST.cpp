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
    * Idea: 1.preorder/inorder/postorder Binary Search Tree, and record the val of each TreeNode into a vector, 
    * then traverse the vector to calculate the sum of each two elements;
    * 2.use a hashmap to record the val of each TreeNode, and check the key before record it
    * 
    */
    bool findTarget(TreeNode* root, int k) {

        // ==1
        vector<int> help;
        preOrder(root, help);
        int n = help.size();
        for(int i = 0; i < n-1; i++){
            for(int j = n-1; j > i; j--){
                if(help[i] + help[j] == k){
                    return true;
                }else if(help[i] + help[j] < k){
                    break;
                }
            }
        }
        return false;

        /*
        // ==2
        if(root == NULL){
            return false;
        }
        map<int, int> help;
        return BFSUtil(root, help, k);
        */
    }
    
    void preOrder(TreeNode* root, vector<int>& help){
        if(root == NULL){
            return ;
        }        
        preOrder(root->left, help);
        help.push_back(root->val);
        preOrder(root->right, help);
    }
    
    void inOrder(TreeNode* root, vector<int>& help){
        if(root == NULL){
            return ;
        }         
        help.push_back(root->val);
        inOrder(root->left, help);
        inOrder(root->right, help);
    }
    
    void postOrder(TreeNode* root, vector<int>& help){
        if(root == NULL){
            return ;
        }        
        postOrder(root->right, help);
        help.push_back(root->val);
        postOrder(root->left, help);
    }
    
    bool BFSUtil(TreeNode* root, map<int, int>& help, int k){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int t = q.front()->val;
            q.pop();
            if(help.find(k-t) != help.end()){
                return true;
            }else{
                help.insert(make_pair(t, 1));   // here, we ignore the case that two TreeNodes have same value
            }
            if(root->left != NULL){
                q.push(root->left);
            }
            if(root->right != NULL){
                q.push(root->right);
            }
        }
        return false;
    }
    
};