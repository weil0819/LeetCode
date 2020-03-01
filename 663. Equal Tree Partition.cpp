/*

663. Equal Tree Partition -- Medium
https://www.leetfree.com/problems/equal-tree-partition.html
http://www.cnblogs.com/grandyang/p/7550360.html

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15

Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.

Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000

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

// Method-I: update each node's value as the sum of all its children
// time cost: O(N), where N is the number of treenode
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        if(root == NULL) return false;
        unordered_map<int, int> helper;
        int sum = compSum(root, helper);
        if(sum == 0) return helper[0] > 1;
        return sum%2==0 && helper.count(sum/2);
    }
private:
    int compSum(TreeNode* node, unordered_map<int,int>& helper) {
        if(node == NULL) return 0;
        // new node value = sum of all children 
        int tmp = node->val + compSum(node->left, helper) + compSum(node->right, helper);
        ++helper[tmp];
        return tmp;
    }
};

// Method-II: using stack to store sum of all its children
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        if(root == NULL) return false;
        int total = compSum(root);
        S.pop();
        if(total%2 == 0) {
            while(!S.empty()) {
                int tmp = S.top();
                S.pop();
                if(tmp == total/2) return true;
            }
        }
        return false;
    }

private:
    stack<int> S;
    int compSum(TreeNode* node) {
        if(node == NULL) return 0;
        S.push(node->val + compSum(node->left) + compSum(node->right));
        return S.top();
    }
};


