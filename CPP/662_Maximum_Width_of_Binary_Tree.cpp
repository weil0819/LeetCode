//===========================================================================================
// 662. Maximum Width of Binary Tree

// Given a binary tree, write a function to get the maximum width of the given tree. 
// The width of a tree is the maximum width among all levels. 
// The binary tree has the same structure as a full binary tree, but some nodes are null.

// The width of one level is defined as the length between the end-nodes 
// (the leftmost and right most non-null nodes in the level, 
// 	where the null nodes between the end-nodes are also counted into the length calculation.

// Example 1:
// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
// Example 2:
// Input: 

//           1
//          /  
//         3    
//        / \       
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
// Example 3:
// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
// Example 4:
// Input: 

//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 
// (6,null,null,null,null,null,null,7).


// Note: Answer will in the range of 32-bit signed integer.
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
	* Idea: BFS problem
	* use queue<pair<TreeNode*, int> > to record the <TreeNode, position>
	* for TreeNode t, if it has left child, t->left's pos = 2*pos -1
	* 				  if it has right child, t->right's pos = 2*pos
	* 
	*/
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
        	return 0;
        }
        queue<pair<TreeNode*, int> > helper;
        helper.push(make_pair(root, 1));
        int res = 1;
        while(!helper.empty()){
        	int n = helper.size();
        	res = max(res, helper.back().second - helper.front().second+1);
        	for(int i = 0; i < n; i++){
        		TreeNode* t = helper.front().first;
        		int pos = helper.front().second;
        		helper.pop();
        		if(t->left){
        			helper.push(make_pair(t->left, 2*pos-1));        			
        		}
        		if(t->right){
        			helper.push(make_pair(t->right, 2*pos));
        		}
        	}
        }
        return res;
    }
};

