//==========================================================================================
// 560. Subarray Sum Equals K

// Given an array of integers and an integer k, you need to find the total number of continuous subarrays 
// whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
//==========================================================================================

class Solution {
public:
	/**
	* Idea: this is preSum problem
	* we can regard sum[i, j] as the sum of continuous subarrays
	* sum[i, j] = sum[j] - sum[i-1]
	* and the we use unordered_map<int, int> to record the <sum[i], #sum[i]>
	*/
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0){
        	return 0;
        }
        int sum = 0, res = 0;
        unordered_map<int, int> helper;
        helper[0] = 1;
        for(int i = 0; i < n; i++){
        	sum += nums[i];
        	res += helper[sum-k];
        	helper[sum]++;
        }
        return res;
    }
};