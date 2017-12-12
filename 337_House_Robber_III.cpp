//===========================================================================================
// 337. House Robber III

// The thief has found himself a new place for his thievery again. 
// There is only one entrance to this area, called the "root." 
// Besides the root, each house has one and only one parent house. 
// After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
// It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Maximum amount of money the thief can rob = 4 + 5 = 9.
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
	* Idea: This is a dynamic programming problem
	* we could use dp[i] to represent the sum of 0 to the i layer
	* 
	* BFS traversal method
	* 
	*/
    int rob(TreeNode* root) {
    	if(root == NULL){
    		return 0;
    	}
        queue<TreeNode*> helper;
        helper.push(root);
        int sumOdd = 0, sumEven = 0;
        int flag = 1;
        while(!helper.empty()){
        	int n = helper.size();
        	for(int i = 0; i < n; i++){
        		TreeNode* t = helper.front();
        		helper.pop();
        		if(flag > 0){
        			sumOdd += t->val;
        		}else{
        			sumEven += t->val;
        		}
        		if(t->left){
        			helper.push(t->left);
        		}
        		if(t->right){
        			helper.push(t->right);
        		}
        	}
        	flag = -flag;
        }

        return sumOdd > sumEven ? sumOdd : sumEven;
    }
};