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
    * Idea: we can use DFS-like algorithm to traverse the tree and record the length of path
    * we construct a recursive function which returns #path whose length is sum starting from node
    * For pathSum function, we also need to recursively call it to consider each node as starting node
    */
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return 0;
        }
        int pre = 0;
        return DFSUtil(root, pre, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int DFSUtil(TreeNode* node, int pre, int sum){
        if(node == NULL){
            return 0;
        }
        int tmp = 0, leftP = 0, rightP = 0;
        pre = pre + node->val; 
        if(pre == sum){
            tmp = 1;
        }
        if(node->left){
            leftP = DFSUtil(node->left, pre, sum);
        }
        if(node->right){
            rightP = DFSUtil(node->right, pre, sum);
        }
        return tmp + leftP + rightP;
    }
};