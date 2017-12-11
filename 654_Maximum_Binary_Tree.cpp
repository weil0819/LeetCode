//===========================================================================================
// 654. Maximum Binary Tree
// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
// Note:
// The size of the given array will be in the range [1,1000].
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
	* Idea: we need to adopt a recursive method to get maximum binary tree from [left, right]
	* 
	*/
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	if(nums.size() == 0){
    		return NULL;
    	}
    	return constructMaximumBinaryTree(nums, 0, nums.size());
    }

    TreeNode* constructMaximumBinaryTree(vector<int> nums, int left, int right){
    	if(left == right){
    		return NULL;
    	}
    	int pos = getMaxPos(nums, left, right);
    	TreeNode* root = new TreeNode(nums[pos]);
    	root->left = constructMaximumBinaryTree(nums, left, pos);
    	root->right = constructMaximumBinaryTree(nums, pos+1, right);
    	return root;
    }

    int getMaxPos(vector<int> array, int left, int right){
    	int pos = left;
    	for(int i = left; i < right; i++){
    		if(array[i] > array[pos]){
    			pos = i;
    		}
    	}
    	return pos;
    }

};

