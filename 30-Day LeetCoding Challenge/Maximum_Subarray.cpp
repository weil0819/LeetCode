/*
Maximum Subarray
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/

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
    // max sum end with nums[i] is the max{nums[i], max sum end with nums[i-1]}
    // that is, maxSum[i] = max{nums[i], maxSum[i-1]}
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        
        int res = nums[0], maxEnd = nums[0];
        for(int i = 1; i < N; i++) {
            maxEnd = max(nums[i], maxEnd + nums[i]);
            if(maxEnd > res) res = maxEnd;
        }        
        
        return res;
    }
};



