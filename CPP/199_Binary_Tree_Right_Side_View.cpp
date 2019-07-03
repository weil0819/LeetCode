//===========================================================================================
// 199. Binary Tree Right Side View
// Given a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].
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
	* Idea: we can use BFS to traverse each layer and keep the last one as one of results
	*
	*/
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> res;
    	if(root == NULL){
    		return res;
    	}
        queue<TreeNode*> helper;
        helper.push(root);
        while(!helper.empty()){
        	int n = helper.size();
        	for(int i = 0; i < (n-1); i++){
        		TreeNode* t = helper.front();
        		helper.pop();
        		if(t->left){
        			helper.push(t->left);
        		}
        		if(t->right){
        			helper.push(t->right);
        		}
        	}
        	TreeNode* t = helper.front();
        	res.push_back(t->val);
        	helper.pop();
        	if(t->left){
        		helper.push(t->left);        		
        	}
        	if(t->right){
        		helper.push(t->right);
        	}
        }

        return res;
    }
};

