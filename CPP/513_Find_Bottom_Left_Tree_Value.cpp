//==========================================================================================
// 513. Find Bottom Left Tree Value

// Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:
// Input:

//     2
//    / \
//   1   3

// Output:
// 1
// Example 2: 
// Input:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// Output:
// 7
// Note: You may assume the tree (i.e., the given root node) is not NULL.
//==========================================================================================

#include <iostream>
#include <queue>
using namespace std;

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
	* Idea: we use BFS to traverse each layer
	* 
	*/
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> help;
        help.push(root);
        int fir;
        while(!help.empty()){
        	int len = help.size();
        	for(int i = 0; i < len; i++){
        		TreeNode* tmp = help.front();
        		if(i == 0){
        			fir = tmp->val;
        		}
        		help.pop();
        		if(tmp->left){
        			help.push(tmp->left);
        		}
        		if(tmp->right){
        			help.push(tmp->right);
        		}
        	}
        } 
        return fir;
    }
};