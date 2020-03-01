/*
333. Largest BST Subtree -- Medium
https://www.leetfree.com/problems/largest-bst-subtree.html

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

Follow up:
Can you figure out ways to solve it with O(n) time complexity?

*/

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Approach #1: Recursion
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
    	if (!root) return 0;
        if (isValid(root, INT_MIN, INT_MAX)) return count(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }

    bool isValid(TreeNode* root, int mn, int mx) {
    	if(!root) return true;
    	if(root->val <= mn || root->right >= mx) return false;
    	return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }

    int count(TreeNode* root) {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }
};


// Approach #2: O(n) time cost
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
    	int res = 0, mn = INT_MIN, mx = INT_MAX;
        bool d = isValidBST(root, mn, mx, res);
        return res;
    }
    
    bool isValidBST(TreeNode *root, int &mn, int &mx, int &res) {
        if (!root) return true;
        int left_n = 0, right_n = 0, left_mn = INT_MIN;
        int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        bool left = isValidBST(root->left, left_mn, left_mx, left_n);
        bool right = isValidBST(root->right, right_mn, right_mx, right_n);
        if (left && right) {
            if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) {
                res = left_n + right_n + 1;
                mn = root->left ? left_mn : root->val;
                mx = root->right ? right_mx : root->val;
                return true;
            }
        }
        res = max(left_n, right_n);
        return false;
    }

