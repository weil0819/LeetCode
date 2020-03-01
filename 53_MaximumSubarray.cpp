class Solution {
public:
    /**
    * Idea: 1.keep adding each integer to the sequence until the sum drops below 0.
    * If sum is negative, then should reset the sequence. 
    * Here, we need a point to record the sum of previous calculation. 
    * sum=-2,preSum=-2 => sum=0 => sum=1,preSum=1 => sum=-2,preSum=1 => sum=0 => 
    * sum=4,preSum=4 => sum=3,preSum=4 => sum=5,preSum=5 => sum=6,preSum=6 => sum=1, preSum=6 => sum=5,preSum=6
    * 2.Dynamic Programming problem. 
    * sub problem should be maxSubArray(int A[], int i), which means the maxSubArray for A[0:i ] which must has A[i] as the end element.
    * maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; 
    * 
    */
    int maxSubArray(vector<int>& nums) {
        /*
        int sum = 0, preSum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            preSum = max(sum, preSum);
            sum = max(sum, 0);
        }
        return preSum;
        */
        int n = nums.size();
        vector<int> dp(n, 0);   //dp[i] means the maximum subarray ending with A[i];
        dp[0] = nums[0];
        int maxLen = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = (dp[i-1] > 0 ? dp[i-1] : 0) + nums[i];
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
        
    }
};