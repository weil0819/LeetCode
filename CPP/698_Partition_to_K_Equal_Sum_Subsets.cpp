//===========================================================================================
// 698. Partition to K Equal Sum Subsets

// Given an array of integers nums and a positive integer k, 
// find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

// Example 1:
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
// Note:

// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: this is a backtracking problem
    * we need to find k subsets whose accumulation is equal to sum/k
    * when accumulation == target, we should consider the next subset and k--
    * 
    */
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0){
            return false;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % k != 0){
            return false;
        }
        sum = sum / k;
        vector<int> visited(n, 0);
        return backtrack(nums, visited, 0, sum, 0, k, 0);
    }

    bool backtrack(vector<int>& nums, vector<int>& visited, int val, int target, int start, int k, int len){
        if(k == 1){
            return true;
        }
        if(val == target && len > 0){
            return backtrack(nums, visited, 0, target, 0, k-1, 0);
        }
        for(int i = start; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                if(backtrack(nums, visited, val+nums[i], target, i+1, k, len+1)){
                    return true;
                }
                visited[i] = 0;
            }
        }
        return false;
    }
};


