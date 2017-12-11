//==========================================================================================
// 508. Most Frequent Subtree Sum

// Given the root of a tree, you are asked to find the most frequent subtree sum. 
// The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). 
// So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

// Examples 1
// Input:

//   5
//  /  \
// 2   -3
// return [2, -3, 4], since all the values happen only once, return all of them in any order.
// Examples 2
// Input:

//   5
//  /  \
// 2   -5
// return [2], since 2 happens twice, however -5 only occur once.
// Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
//==========================================================================================

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /**
     * Idea: use DFS to compute the sum of each Subtree
     * use a unordered_map<int, int> to record the <sum, frequent>
     *
     */
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFreq;
        vector<int> output;
        if(root == NULL){
            return output;
        }
        int sumR = postOrder(root, sumFreq);
        int maxF = 1, res = INT_MIN;
        for(unordered_map<int, int>::iterator it = sumFreq.begin(); it != sumFreq.end(); ++it){
            if(it->second > maxF){
                maxF = it->second;
                res = it->first;
            }        
        }

        for(unordered_map<int, int>::iterator it = sumFreq.begin(); it != sumFreq.end(); ++it){
            if(it->second == maxF){
                output.push_back(it->first);
            }
        }

        return output;

    }
    int postOrder(TreeNode* node, unordered_map<int, int>& sumFreq){
        int leftS = 0, rightS = 0;
        if(node->left){
            leftS = postOrder(node->left, sumFreq);
        }
        if(node->right){
            rightS = postOrder(node->right, sumFreq);
        }
        int sum = node->val + leftS + rightS;
        if(sumFreq.find(sum) != sumFreq.end()){
            ++sumFreq[sum];
        }else{
            sumFreq.insert(make_pair(sum, 1));
        }
        return sum;
    }
}
