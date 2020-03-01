/*

298. Binary Tree Longest Consecutive Sequence -- Medium
http://www.leetfree.com/problems/binary-tree-longest-consecutive-sequence.html

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,

   1
    \
     3
    / \
   2   4
        \
         5

Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1

Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

*/

/*
求二叉树的最长连续序列
*/
class Solution {
private:
    void dfs(TreeNode *root, int v, int out, int &res) {
        if (!root) return;
        if (root->val == v + 1) ++out;
        else out = 1;
        res = max(res, out);
        dfs(root->left, root->val, out, res);
        dfs(root->right, root->val, out, res);
    }    
public:
    /*
    Method-I: preorder遍历(root-->left-->right)
    我们对于每个遍历到的节点，我们看节点值是否比参数值(父节点值)大1，
    如果是则长度加1，否则长度重置为1，然后更新结果res，再递归调用左右子节点即可
    */
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val, 0, res);
        return res;
    }

    /*
    Method-II: 以层序来遍历树，对于遍历到的节点，我们看其左右子节点有没有满足题意的，
    如果左子节点比其父节点大1，若右子节点存在，则排入queue，指针移到左子节点，
    反之若右子节点比其父节点大1，若左子节点存在，则排入queue，指针移到右子节点，依次类推直到queue为空
    */
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = 1;
            TreeNode *t = q.front(); q.pop();
            while ((t->left && t->left->val == t->val + 1) || (t->right && t->right->val == t->val + 1)) {
                if (t->left && t->left->val == t->val + 1) {
                    if (t->right) q.push(t->right);
                    t = t->left;
                } else if (t->right && t->right->val == t->val + 1) {
                    if (t->left) q.push(t->left);
                    t = t->right;
                }
                ++len;
            }
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            res = max(res, len);
        }
        return res;
    }    
};