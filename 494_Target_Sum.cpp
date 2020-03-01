//===========================================================================================
// 494. Target Sum

// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
// Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.
// Note:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: This is recursion problem
	* In recursion function, we set a parameter cnt to indicate the number of scanned integers
	* and a parameter sum to represent the current sum, and the return value is the number of ways
	* 
	*/
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt = 0, sum = 0;
        // return recur(nums, cnt, sum, S);
        int res = 0;
        recur(nums, cnt, sum, S, res);
        return res;
    }

    int recur(vector<int> nums, int cnt, int sum, int S){
    	if(cnt == nums.size()){
    		if(sum == S){
    			return 1;
    		}
    	}else{
    		return recur(nums, cnt+1, sum+nums[cnt], S) + recur(nums, cnt+1, sum-nums[cnt], S);
    	}
    }

    void recur(vector<int> nums, int cnt, int sum, int S, int& res){
    	if(cnt == nums.size()){
    		if(sum == S){
    			++res;
    		}
    	}else{
    		recur(nums, cnt+1, sum+nums[cnt], S, res);
    		recur(nums, cnt+1, sum-nums[cnt], S, res);
    	}
    }
};