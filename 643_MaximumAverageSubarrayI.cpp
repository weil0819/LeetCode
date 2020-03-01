class Solution {
public:
    /**
    * Idea: 1.straightforward scan the array until the n-k
    * INT_MAX = 2^31-1，INT_MIN = -2^31
    * 2.sliding-window method:
    * we compute sum of the first k elements, and then move one step by computing the difference nums[i]-nus[i-k]
    * we can get sum + nums[i]-nus[i-k] is equal to the sum of next k elements
    * 
    */
    /*
    // Method-I
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = -10000;
        for(int i = 0; i <= n-k; i++){
            double avg = 0.0;
            for(int j = i; j < (i+k); j++){
                avg += nums[j];
            }            
            avg = avg/k;  
            if((avg-maxAvg) > 1e-6){
                maxAvg = avg;
            }
        }
        return maxAvg;
    }
    */
    // Method-II
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i < k){
                sum += nums[i];
            }else{
                maxSum = max(maxSum, sum);
                sum += nums[i] - nums[i-k];
            }
        }
        // the last sum must be compared with maxSum
        maxSum = max(maxSum, sum);
        return (double)maxSum/k;
    }
};