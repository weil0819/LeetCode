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
    * Idea: 1.we can construct an auxiliary function which traverses the Tree in preOder to compute the depth of each leaf,
    * and compare it with the minDepth value
    * 2.we can also directly use recursive method
    * 
    */
    // Method-I
    /*
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int dep = 1, minD = INT_MAX;
        depth(root, minD, dep);
        return minD;
    }
    void depth(TreeNode* node, int& minD, int dep){
        if(!node->left && !node->right){
            if(dep < minD){
                minD = dep;
            }
        }else{
            ++dep;
            if(node->left){
                depth(node->left, minD, dep);
            }
            if(node->right){
                depth(node->right, minD, dep);
            }            
        }
    }
    */
    //Method-II
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }

        int leftD = 1, rightD = 1;
        if(root->left){
            leftD = minDepth(root->left) + 1;
        }
        if(root->right){
            rightD = minDepth(root->right) + 1;
        }
        if(!root->left || !root->right){
            return max(leftD, rightD);
        }
        return min(leftD, rightD);
    }    
};