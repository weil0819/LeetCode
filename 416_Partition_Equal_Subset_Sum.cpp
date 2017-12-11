//===========================================================================================
// 416. Partition Equal Subset Sum

// Given a non-empty array containing only positive integers, 
// find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a backtracking problem
	* ==> TLE=Time Limit Exceeded
	* 
	*/
    /*
    bool canPartition(vector<int>& nums) {
    	if(nums.size() == 0){
    		return false;
    	}
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
        	total += nums[i];
        }
        if(total % 2 == 1){
            return false;
        }
        return backtrack(nums, 0, 0, total);
    }

    bool backtrack(vector<int>& nums, int start, int sum, int total){
    	if(sum >= total/2){
    		return sum == total/2;
    	}
    	for(int i = start; i < nums.size(); i++){
    		if(backtrack(nums, i+1, sum+nums[i], total)){
    			return true;
    		}
    	}
    	return false;
    }
    */
    /**
    * Idea: this is a 0/1 knapsack problem
    * dp[j] denotes whether the specific sum j can be gotten
    * for j, there are different cases:
    * 1) we don't pick nums[i], dp[j] = dp[j].
    * 2) we pick nums[i], dp[j] = dp[j-nums[i]].
    * 
    */
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return true;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        sum = sum / 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = sum; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }

};
