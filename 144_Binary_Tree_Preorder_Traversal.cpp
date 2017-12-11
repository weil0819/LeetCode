//===========================================================================================
// 144. Binary Tree Preorder Traversal

// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

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
	* Idea: For interation method, we need use queue or stack
	* Here, we use a stack<TreeNode*> to record all nodes
	* we should push right subtree first and then left subtree
	* 
	*/
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
        	return res;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
        	TreeNode* t = s.top();
        	res.push_back(t->val);
        	s.pop();
        	if(t->right){
        		s.push(t->right);
        	}
        	if(t->left){
        		s.push(t->left);
        	}
        }

        return res;
    }
};
