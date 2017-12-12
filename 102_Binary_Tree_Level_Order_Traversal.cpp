//===========================================================================================
// Given a binary tree, return the level order traversal of its nodes' values. 
// (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
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
	* Idea: BFS traversal
	* 
	*/
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int> > res;
    	if(root == NULL){
    		return res;
    	}
    	queue<TreeNode*> helper;
    	helper.push(root); 
    	while(!helper.empty()) {
    		int n = helper.size();
    		vector<int> tmp;
    		for(int i = 0; i < n; i++){
    			TreeNode* t = helper.front();
    			tmp.push_back(t->val);    			
    			helper.pop();
    			if(t->left){
    				helper.push(t->left);
    			}
    			if(t->right){
    				helper.push(t->right);
    			}
    		}
    		res.push_back(tmp);
    	}
    	return res;     
    }
};
