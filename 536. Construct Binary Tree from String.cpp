/*

536. Construct Binary Tree from String -- Medium
https://www.leetfree.com/problems/construct-binary-tree-from-string.html
http://www.cnblogs.com/grandyang/p/6793904.html

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, 
one or two pairs of parenthesis. The integer represents the root's value and a pair of 
parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".

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


// Method-I: recursion
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        auto found = s.find('(');
        int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
        TreeNode *cur = new TreeNode(val);
        if (found == string::npos) return cur;
        int start = found, cnt = 0;
        for (int i = start; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') --cnt;
            if (cnt == 0 && start == found) {
                cur->left = str2tree(s.substr(start + 1, i - start - 1));
                start = i + 1;
            } else if (cnt == 0) {
                cur->right = str2tree(s.substr(start + 1, i - start - 1));
            }
        }
        return cur;
    }
};


// Method-II: Iteration by stack
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        stack<TreeNode*> st;
        for (int i = 0; i < s.size(); ++i) {
            int j = i;		// record current index
            // Case-I: '(', skip
            // Case-II: '0'-'9', creae new node
            // Case-III: remove parent node
            if (s[i] == ')') st.pop();
            else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') ++i;
                TreeNode *cur = new TreeNode(stoi(s.substr(j, i - j + 1)));
                if (!st.empty()) {
                    TreeNode *t = st.top();
                    if (!t->left) t->left = cur;
                    else t->right = cur;
                }
                st.push(cur);
            }
        }
        return st.top();
    }
};


