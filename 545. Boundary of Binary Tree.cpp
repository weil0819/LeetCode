/*

545. Boundary of Binary Tree -- Medium
https://www.leetfree.com/problems/boundary-of-binary-tree.html
http://www.cnblogs.com/grandyang/p/6833459.html

Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. 
Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. 
Right boundary is defined as the path from root to the right-most node. 
If the root doesn't have left subtree or right subtree, 
then the root itself is left boundary or right boundary. 
Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when 
you always firstly travel to the left subtree if exists. 
If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should 
output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].

Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

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


// Method-I: three recursion
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
      if(root == NULL) return {};
      vector<int> res;
      if(root->left || root->right) return res.push_back(root->val);
      leftBoundary(root->left, res);
      leaves(root, res);
      rightBoundary(root->right, res);
      return res;
    }

private:
    void leftBoundary(TreeNode* node, vector<int>& res) {
      // Case-I: left-most node will be regarded as leaf node.
      if(node == NULL || (node->left == NULL && node->right == NULL)) return;
      res.push_back(node->val);
      // Case-II: having left child and no left child
      if(node->left == NULL) leftBoundary(node->right, res);
      else leftBoundary(node->left, res);
    }

    void leaves(TreeNode* node, vector<int>& res) {
      if(node == NULL) return;
      if(node->left == NULL && node->right == NULL) res.push_back(node->val);
      leaves(node->left, res);
      leaves(node->right, res);
    }

    void rightBoundary(TreeNode* node, vector<int>& res) {
      if(node == NULL || (node->left == NULL && node->right == NULL)) return;
      if(node->right == NULL) rightBoundary(node->left, res);
      else rightBoundary(node->right, res);
      res.push_back(node->val);
    }
};


// Method-II: one recursion
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res{root->val};
        helper(root->left, true, false, res);
        helper(root->right, false, true, res);
        return res;
    }

private:
    // leftbd: is left boundary?; rightbd: is right boundary?
    void helper(TreeNode* node, bool leftbd, bool rightbd, vector<int>& res) {
        if (node == NULL) return;
        // Case-I: leaf node
        if (node->left == NULL && node->right == NULL) {
            res.push_back(node->val);
            return;
        }
        // Case-II: left boundary node
        if (leftbd) res.push_back(node->val);
        helper(node->left, leftbd && node->left, rightbd && !node->right, res);
        helper(node->right, leftbd && !node->left, rightbd && node->right, res);
        // Case-III: right boundary node
        if (rightbd) res.push_back(node->val);
    }
};

// Method-III: Iteration
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res, right;
        TreeNode *l = root->left, *r = root->right, *p = root;
        if (root->left || root->right) res.push_back(root->val);
        while (l && (l->left || l->right)) {
            res.push_back(l->val);
            if (l->left) l = l->left;
            else l = l->right;
        }
        stack<TreeNode*> st;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                if (!p->left && !p->right) res.push_back(p->val);
                p = p->left;
            } else {
                p = st.top(); st.pop();
                p = p->right;
            }
        }
        while (r && (r->left || r->right)) {
            right.push_back(r->val);
            if (r->right) r = r->right;
            else r = r->left;
        }
        res.insert(res.end(), right.rbegin(), right.rend());
        return res;
    }
};


