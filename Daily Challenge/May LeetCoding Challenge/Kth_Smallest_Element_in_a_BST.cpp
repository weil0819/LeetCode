/*
Kth Smallest Element in a BST

@date: May 20, 2020

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
    // For BST, the in-order traversal is in ascending order
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0, res = root->val;
        inOrder(root, k, idx, res);
        return res;
    }
private:
    // idx is the increasing index, res is the return value
    void inOrder(TreeNode* node, int k, int& idx, int& res) {
        // Order is left-root-right
        if(node->left) inOrder(node->left, k, idx, res);
        idx++;
        if(idx == k) {
            res = node->val;
            return ;
        }
        if(node->right) inOrder(node->right, k, idx, res);
    }
    
    // Follow-up:
    // Insert and delete in a BST, the time complexity of these operations is O(H), where H is a height of binary tree, and H=O(logN) for the balanced tree.
    // without any optimisation insert/delete + search of kth element has O(2H+k) complexity
    // If we use double linked list to work as index for BST, the complexity will be O(H+k), where O(H) for insert/delete and O(k) for kth search
};


