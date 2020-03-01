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
    * Idea: Based on the concept of special binary tree, we know that the root must have the smallest value    
    * the second smallest must be in the subtree with same value with that of root
    * We must adopt DFS search to check the subtree whose root has same value with root's
    * We construct a help function which returns smallest value between it left and right subtree
    */
    int findSecondMinimumValue(TreeNode* root) {      

        int smallest = root->val;
        return DFSUtil(root, smallest);
    }
    
    int DFSUtil(TreeNode* node, int smallest){
        if(node == NULL){
            return -1;
        }        
        if(node->val != smallest){
            return node->val;   // we don't need to traverse this subtree
        }
        int leftV, rightV;
        leftV = DFSUtil(node->left, smallest);
        rightV = DFSUtil(node->right, smallest);      
        if(leftV == -1){
            return rightV;
        }
        if(rightV == -1){
            return leftV;
        }
        return min(leftV, rightV);
    }
};