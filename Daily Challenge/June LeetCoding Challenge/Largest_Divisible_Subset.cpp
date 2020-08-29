/*
Largest Divisible Subset

@date: June 13, 2020

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

class Solution {
public:
    // DP + back-propogation
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return vector<int>();
        
        vector<int> res;
        int maxLen = 0, maxIdx = 0; // max length of largest subset and the last index
        vector<int> dp(N, 0);   // dp[i] is the length of largest subset end with nums[i]
        vector<int> pre(N, 0);  // pre[i] is the previous element of nums[i] if nums[i] is selected
        sort(nums.begin(), nums.end()); // sort the "nums" first
        for(int i = 0; i < N; i++) {
            for(int j = i; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1+dp[j]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        for(int i = 0; i < maxLen; i++) {
            res.push_back(nums[maxIdx]);
            maxIdx = pre[maxIdx];
        }
        sort(res.begin(), res.end());
        return res;
    }
};
