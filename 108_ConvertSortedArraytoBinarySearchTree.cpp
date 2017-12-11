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
    * Idea: Since we want to construct a balanced BST, the middle element in array should be root.
    * Thus, we can adopt binary search algorithm
    * construct a recursive function which returns a TreeNode
    * Attention: If we set stop condition as low > high, left=[low, mid-1], right=[mid+1, high]
    * 
    */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }
        int low = 0, high = nums.size()-1;
        return binarySearch(nums, low, high);
    }
    
    TreeNode* binarySearch(vector<int> nums, int low, int high){
        if(low > high){
            return NULL;
        }
        int mid = (low + high)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = binarySearch(nums, low, mid-1);
        node->right = binarySearch(nums, mid+1, high);
        return node;
    }
};