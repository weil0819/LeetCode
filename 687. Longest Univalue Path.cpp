/*

687. Longest Univalue Path -- Easy

Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    /**
    * Idea: we can use DFS to compute the univalue path from each TreeNode
    * auxiliary function should have two parameters: current TreeNode and current maximum univalue path
    * auxiliary function should return the maximum univalue path which starts from current TreeNode
    * Thus, the final output should be the parameter which records current maximum univalue path
    *
    */
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int dep = 0;
        postOrder(root, dep);
        return dep;
    }
    
    int postOrder(TreeNode* node, int& dep){
        int leftD = 0, rightD = 0;
        if(node->left){
            leftD = postOrder(node->left, dep);
        }
        if(node->right){
            rightD = postOrder(node->right, dep);
        }
        int partL = 0, partR = 0;
        // If current node has left child and its left child's val==val
        if(node->left && node->left->val == node->val){
            partL = leftD + 1;
        }
        if(node->right && node->right->val == node->val){
            partR = rightD + 1;
        }
        dep = max(dep, partL+partR);
        return max(partL, partR);
    }    
};


// Utility functions
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

// main function
int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().longestUnivaluePath(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}