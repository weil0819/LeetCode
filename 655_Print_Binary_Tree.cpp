//==========================================================================================
// 655. Print Binary Tree

// Print a binary tree in an m*n 2D string array following these rules:

// The row number m should be equal to the height of the given binary tree.
// The column number n should always be an odd number.
// The root node's value (in string format) should be put in the exactly middle of the first row it can be put. 
// The column and the row where the root node belongs will separate the rest space into two parts 
// (left-bottom part and right-bottom part). 
// You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. 
// The left-bottom part and the right-bottom part should have the same size. 
// Even if one subtree is none while the other is not, 
// you don't need to print anything for the none subtree but still need to leave the space 
// as large as that for the other subtree. However, if two subtrees are none, 
// then you don't need to leave space for both of them.
// Each unused space should contain an empty string "".
// Print the subtrees following the same rules.
// Example 1:
// Input:
//      1
//     /
//    2
// Output:
// [["", "1", ""],
//  ["2", "", ""]]
// Example 2:
// Input:
//      1
//     / \
//    2   3
//     \
//      4
// Output:
// [["", "", "", "1", "", "", ""],
//  ["", "2", "", "", "", "3", ""],
//  ["", "", "4", "", "", "", ""]]
// Example 3:
// Input:
//       1
//      / \
//     2   5
//    / 
//   3 
//  / 
// 4 
// Output:

// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
//  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
//  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
//  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
// Note: The height of binary tree is in the range of [1, 10].
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
	* Idea: Firstly, we need to compute the height of this tree,
	* and then calculate the number of columns in each row = 2^{height}-1
	* After that, we can consider the recursive method and DFS method
    * We have observations that: 
    * 1's pos = (0+14)/2 = 7, 2's pos = (0+6)/2 = 3, 5's pos = (14+8)/2 = 11
    * 3's pos = (0+2)/2 = 1, 4's pos = (0+0)/2 = 0
    * Above is still a recursive problem:
    * pos is the position of parent node in curRow,
    * left side's range = [start, pos-1], right side's range = [pos+1, end]
    *  
	*/
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string> > res;
        if(root == NULL){
            return res;
        }
        int height = getHeight(root);
        int columns = (int)pow(2, height) - 1;
        res.reserve(height);
        for(int i = 0; i < height; i++){
            vector<string> tmp(columns, "");
            res.push_back(tmp);
        }
        help(res, root, 0, height, 0, columns-1);
        return res;
    }

    void help(vector<vector<string> >& res, TreeNode* node, int curRow, int height, int start, int end){
        if(curRow == height || node == NULL){
            return ;
        }
        int pos = (start+end)/2;
        res[curRow][pos] = to_string(node->val);
        help(res, node->left, curRow+1, height, start, pos-1);
        help(res, node->right, curRow+1, height, pos+1, end);
    }

    // recursion
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftH = 0, rightH = 0;
        if(root->left){
            leftH = getHeight(root->left);
        }
        if(root->right){
            rightH = getHeight(root->right);
        }
        return max(leftH, rightH) + 1;
    }
};
