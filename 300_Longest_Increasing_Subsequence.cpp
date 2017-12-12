//===========================================================================================
// 300. Longest Increasing Subsequence

// Given an unsorted array of integers, find the length of longest increasing subsequence.

// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
// Note that there may be more than one LIS combination, it is only necessary for you to return the length.

// Your algorithm should run in O(n2) complexity.

// Follow up: Could you improve it to O(n log n) time complexity?
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a DP problem
	* dp[i] = max{dp[j]}+1, where j < i & nums[j] < nums[i]
	* dp[0] = 1
	* we should compute dp[i] from 0 to n-1
	* for dp[i], we need to select the maximum value among {dp[i-1], dp[i-2], ..., dp[0]}
	* 
	*/
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
        	return 0;
        }
        vector<int> dp(n);
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < n; i++){
        	int maxL = 0;
        	for(int j = i-1; j >= 0; j--){
        		if(nums[j] < nums[i]){
        			maxL = max(dp[j], maxL);
        		}
        	}
        	dp[i] = maxL + 1;
        	res = max(dp[i], res);
        }
        return res;
    }
};
