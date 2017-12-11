//===========================================================================================
// 740. Delete and Earn

// Given an array nums of integers, you can perform operations on the array.

// In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
// After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

// You start with 0 points. Return the maximum number of points you can earn by applying such operations.

// Example 1:
// Input: nums = [3, 4, 2]
// Output: 6
// Explanation: 
// Delete 4 to earn 4 points, consequently 3 is also deleted.
// Then, delete 2 to earn 2 points. 6 total points are earned.
// Example 2:
// Input: nums = [2, 2, 3, 3, 3, 4]
// Output: 9
// Explanation: 
// Delete 3 to earn 3 points, deleting both 2's and the 4.
// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
// 9 total points are earned.
// Note:

// The length of nums is at most 20000.
// Each element nums[i] is an integer in the range [1, 10000].
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a DP problem
	* we can observe that same integer can be accumulated
	* for i, we have two cases:
	* 1) delete helper[i], and earn dp[i-2]+helper[i] since helper[i-1] and helper[i+1] will be deleted
	* 2) don't delete helper[i], and earn dp[i-1]
	* so, dp[i] = max(dp[i-1], dp[i-2]+helper[i])
	*  
	*/
    int deleteAndEarn(vector<int>& nums) {
        vector<int> helper(10001, 0);
        for(int i = 0; i < nums.size(); i++){
        	helper[nums[i]] += nums[i];
        }

        vector<int> dp(10002, 0);
        dp[1] = helper[1];
        dp[2] = max(dp[1], helper[2]);
        for(int i = 3; i <= 10000; i++){
        	dp[i] = max(dp[i-1], helper[i]+dp[i-2]);
        }
        return dp[10000];
    }
};
