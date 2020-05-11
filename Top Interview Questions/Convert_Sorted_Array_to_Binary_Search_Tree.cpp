/*
Convert Sorted Array to Binary Search Tree
https://leetcode.com/explore/featured/card/top-interview-questions-easy/94/trees/631/

@date: May 11, 2020

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Binary search 
    // the middle element should be the root 
    // root->left = BS(left side)
    // root->right = BS(right side)
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return NULL;
        
        int low = 0, high = N-1;
        return binarySearch(nums, low, high);
    }
private:
    TreeNode* binarySearch(vector<int>& nums, int low, int high) {
        if(low > high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = binarySearch(nums, low, mid-1);
        node->right = binarySearch(nums, mid+1, high);
        return node;
    }
};

