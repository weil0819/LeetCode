//==========================================================================================
// 515. Find Largest Value in Each Tree Row

// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]
//==========================================================================================


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
	* Idea: use BFS to scan each row
	* 
	*/
    vector<int> largestValues(TreeNode* root) {
        vector<int> output;
        if(root == NULL){
        	return output;
        }    	
        queue<TreeNode*> help;
        help.push(root);

        while(!help.empty()){
        	int n = help.size();
        	int maxV = INT_MIN;
        	for(int i = 0; i < n; i++){
        		TreeNode* t = help.front();
        		if(t->val > maxV){
        			maxV = t->val;
        		}
        		help.pop();
        		if(t->left){
        			help.push(t->left);
        		}
        		if(t->right){
        			help.push(t->right);
        		}
        	}
        	output.push_back(maxV);
        }
        return output;
    }
};

