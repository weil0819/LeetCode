//===========================================================================================
// 230. Kth Smallest Element in a BST

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
// How would you optimize the kthSmallest routine?
//===========================================================================================

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
	* Idea: For BST problem, we first consider the inOrder traversal
	* if the BST is modified (insert/delete operations) often, we can use an array to 
	* record each value during inOrder traversal
	* 
	*/
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, res = INT_MIN;
        inOrder(root, k, cnt, res);
        return res;
    }

    void inOrder(TreeNode* node, int k, int& cnt, int& res){
    	if(node->left){
    		inOrder(node->left, k, cnt, res);
    	}
    	++cnt;
    	if(cnt == k){
    		res = node->val;
    		return ;
    	}
    	if(node->right){
    		inOrder(node->right, k, cnt, res);
    	}
    }
};