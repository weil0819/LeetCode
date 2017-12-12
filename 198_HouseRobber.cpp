class Solution {
public:
    /**
    * Idea: For a house i, we can rob i or not rob i
    * If we rob i, we must not rob i-1, we can get money = nums[i] + dp[i-1][0]
    * If we not rob i, we can rob i-1 or not rob i-1, we can get money = max(dp[i-1][0], dp[i-1][1])
    * 
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<vector<int> > dp(n, vector<int>(2,0));   
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i][1] = nums[i] + dp[i-1][0];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);            
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};