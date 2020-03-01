/*
285. Inorder Successor in BST -- Medium
https://www.leetfree.com/problems/inorder-successor-in-bst.html
http://www.cnblogs.com/grandyang/p/5306162.html

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

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


// Approach #1: Iteration
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	stack<TreeNode*> S;		// store all visited nodes
    	TreeNode* node = root;
    	bool flag = false;		// indicate p is visited or not

    	while(!S.empty() || node) {
    		while(node) {		// put all left nodes into S
    			S.push(node);	
    			node = node->left;
    		}
    		node = S.top();
    		S.pop();
    		if(flag) return node;	// if p is visited, node should be the successor
    		if(node == p) flag = true;
    		node = node->right;
    	}
    	return NULL;
    }
};


// Approach #2: Recursion
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	if(!p) return NULL;
    	inorder(root, p);
    	return suc;
    }

    void inorder(TreeNode* node, TreeNode* p) {
    	if(!node) return;
    	inorder(node->left, p);
    	if(pre == p) suc = node;
    	pre = node; 
    	inorder(node->right, p);
    }

private:
	TreeNode* pre = NULL, suc = NULL;		// precursor and successor
};



// Approach #3: Iteration
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	TreeNode *res = NULL;

        while (root) {
            if (root->val > p->val) {	// p should be in left-subtree
                res = root;
                root = root->left;
            } else root = root->right;	// p should be in right-subtree
        }
        return res;
    }
};


// Approach #4: Recursion
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	if (!root) return NULL;
        if (root->val <= p->val) {		// p should be in right-subtree
            return inorderSuccessor(root->right, p);
        } else {						// p should be in left-subtree
            TreeNode *left = inorderSuccessor(root->left, p);
            return left ? left : root;	// root or left-subtree node maybe successor
        }
    }
};
