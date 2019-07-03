//===========================================================================================
// 129. Sum Root to Leaf Numbers

// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25.
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
	* Idea: this is a DFS problem
	* 
	*/
    int sumNumbers(TreeNode* root) {
    	if(root == NULL){
    		return 0;
    	}
        int preSum = 0, sum = 0;
        preOrder(preSum, root, sum);
        return sum;
    }

    void preOrder(int preSum, TreeNode* node, int& sum){
    	preSum = preSum*10 + node->val;
    	if(!node->left && !node->right){
    		sum += preSum;
    	}
    	if(node->left){
    		preOrder(preSum, node->left, sum);
    	}
    	if(node->right){
    		preOrder(preSum, node->right, sum);
    	}
    }
};
