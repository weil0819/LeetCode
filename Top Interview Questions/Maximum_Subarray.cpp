/*
Maximum Subarray
https://leetcode.com/explore/featured/card/top-interview-questions-easy/97/dynamic-programming/566/

@date: May 15, 2020

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

class Solution {
public:
    // Assume dp[i] is max sum end with nums[i] (must include nums[i])
    // If dp[i] < 0, return nums[i]
    // Else return dp[i-1] + nums[i]
    // In summary, dp[i] = max(nums[i], dp[i-1]+nums[i])
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        
        int maxSum = nums[0]; // max sum end with nums[i]
        int res = nums[0];    // return value 
        for(int i = 1; i < N; i++) {
            maxSum = max(maxSum+nums[i], nums[i]);
            res = max(res, maxSum);
        }
        return res;
    }
};



