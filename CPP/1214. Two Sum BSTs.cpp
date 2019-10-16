/*

1214. Two Sum BSTs -- Medium
https://leetcode.com/problems/two-sum-bsts/

Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:



Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
Example 2:



Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
 

Constraints:

Each tree has at most 5000 nodes.
-10^9 <= target, node.val <= 10^9

*/

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
    // Method-I: recursive solution -- Time Limit Exceeded
    /*
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL || root2 == NULL) return false;
        
        // Compute sum of two values.
        int sum = root1->val + root2->val;
        if(sum == target) return true;
        else if(sum < target) return twoSumBSTs(root1->right, root2, target) || twoSumBSTs(root1, root2->right, target);
        else return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1, root2->left, target);
    }
    */
    
    // Method-II: iterative solution
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL || root2 == NULL) return false;
        
        stack<TreeNode*> S1, S2;
        
        while(true) {
            while(root1) {
                S1.push(root1);         // top of S1 is the smallest one
                root1 = root1->left;
            }
            while(root2) {
                S2.push(root2);         // top of S2 is the largest one
                root2 = root2->right;
            }
            if(S1.empty() || S2.empty()) return false;
            
            TreeNode* t1 = S1.top();    // the smallest one in the first tree
            TreeNode* t2 = S2.top();    // the largest one in the second tree
            
            int sum = t1->val + t2->val;
            if(sum == target) return true;
            else if(sum < target) {
                S1.pop();
                root1 = t1->right;
            } else {
                S2.pop();
                root2 = t2->left;
            }                        
        }
        return false;        
    }
    
};
