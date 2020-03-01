/*
314. Binary Tree Vertical Order Traversal -- Medium
http://www.leetfree.com/problems/binary-tree-vertical-order-traversal.html

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

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

/*
已知一颗二叉树，求垂直遍历的结果
*/
class Solution{
public:
    /*
    使用map<int, vector<int> > 记录position和对应的vals
    BFS扫描Tree，使用queue<pair<TreeNode*, int> >记录树节点和对应的列号
    列号以root为0，root的左孩子就是-1，右孩子就是1
    */
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        vector<vector<int>> rlt;
        queue<pair<TreeNode*, int>> q;    // 
        if(root)
            q.push(pair<TreeNode*, int>(root, 0));  // <TreeNode, position>
        //Let's BFS!
        while(!q.empty()){
            int size = q.size();         // scan each layer in each iteration
            while(size-- > 0){
                pair<TreeNode*, int> cur = q.front();
                q.pop();
                map[cur.second].push_back(cur.first->val);
                if(cur.first->left != NULL)
                    q.push(pair<TreeNode*, int>(cur.first->left, cur.second-1));
                if(cur.first->right != NULL)
                    q.push(pair<TreeNode*, int>(cur.first->right, cur.second+1));
            }
        }
        //return
        for(auto p : map){
            rlt.push_back(p.second);
        }
        return rlt;
    }	
};

