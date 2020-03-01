/*
173. Binary Search Tree Iterator
https://leetcode.com/problems/binary-search-tree-iterator/description/

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
	/**
	* Idea: For a BST, 
	*			5
	*		3		7
	*	  2	  4   6   8
	* in stack--helper, 5->3->2(top)
	* return 1 as the smallest number in BST
	*  
	*/
private:
	stack<TreeNode*> helper;

public:
    BSTIterator(TreeNode *root) {
        findLeftChild(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !helper.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = helper.top();
        helper.pop();
        findLeftChild(p->right);
        return p->val;
    }

    void findLeftChild(TreeNode* root){
    	TreeNode* p = root;
    	while(p != NULL){
    		helper.push(p);
    		p = p->left;
    	}
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */