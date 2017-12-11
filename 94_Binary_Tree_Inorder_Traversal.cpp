//===========================================================================================
// 94. Binary Tree Inorder Traversal

// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

// Note: Recursive solution is trivial, could you do it iteratively?
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
	* Idea: left->center->right
	* 
	*/

	// Method-I: with Time complexity: O(n) and Space complexity: The worst case space required is O(n), and in the average case it's O(log(n)) 
	/*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
        	return res;
        }

        inOrder(root, res);
        return res;
    }

    void inOrder(TreeNode* node, vector<int>& res){
    	if(node->left){
    		inOrder(node->left, res);
    	}

    	res.push_back(node->val);
    	if(node->right){
    		inOrder(node->right, res);
    	}
    }
	*/

	// Method-II: with Time complexity : O(n) and Space complexity : O(n)
    vector<int> inorderTraversal(TreeNode* root) {
    	stack<TreeNode*> q;
    	vector<int> res;
    	TreeNode* t = root;
    	while(t != NULL || !q.empty()){
    		while(t != NULL){
    			q.push(t);
    			t = t->left;
    		}    		    
    		t = q.top();
    		q.pop();
    		res.push_back(t->val);
    		t = t->right;	    		
    	}
    	return res;
    }

};