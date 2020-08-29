/*
Construct Binary Search Tree from Preorder Traversal

@date: May 24, 2020

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Method-I: O(NlogN)
    /*
    // According to Preorder traversal, we adopt recursive method
    // the first node is Root, and its left-child is Left-Root for left-tree
    // the first node larger than Root is Right-Root for right-tree
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int N = preorder.size();
        if(N == 0) return NULL;
        
        return BSTUtil(preorder, 0, N-1);
    }
    
private:
    TreeNode* BSTUtil(vector<int>& preorder, int begin, int end) {
        if(begin > end) return NULL;
        
        // preorder[begin] should be Root Node
        TreeNode* root = new TreeNode(preorder[begin]);
        
        // the first node larger than preorder[begin] should be Right-Root Node
        int mid = -1;
        for(int i = begin+1; i <= end; i++) {
            if(preorder[i] > root->val) {
                mid = i;
                break;
            }
        }
        
        // build left tree and right tree respectively
        if(mid == -1) {
            root->left = BSTUtil(preorder, begin+1, end);
            root->right = NULL;
        }
        else {
            root->left = BSTUtil(preorder, begin+1, mid-1);
            root->right = BSTUtil(preorder, mid, end);
        }
        return root;
    }
    */
    
    // Method-II: O(N)
    // set up bound for left and right tree
    // left bound should be Root
    // right bound should be infinite
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int N = preorder.size();
        if(N == 0) return NULL;
        
        return BSTUtil(preorder);
    }
    
private:
    int i = 0;      // index of preorder
    
    TreeNode* BSTUtil(vector<int>& preorder, int bound = INT_MAX) {
        if(preorder.size() == i || preorder[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = BSTUtil(preorder, root->val);
        root->right = BSTUtil(preorder, bound);
        
        return root;
    }
    
};


