//===========================================================================================
// 377. Combination Sum IV

// Given an integer array with all positive numbers and no duplicates, 
// find the number of possible combinations that add up to a positive integer target.

// Example:

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers?
//===========================================================================================

class Solution {
public:
	/**
	* Idea: 1)this is a recursion problem
	* Time Limit Exceeded
	* 2)this is a dp problem
	* 
	*/
	// Method-I:
	/*
    int combinationSum4(vector<int>& nums, int target) {
    	if(target == 0){
    		return 1;
    	}
    	int res = 0;
        for(int i = 0; i < nums.size(); i++){
        	if(target >= nums[i]){
        		res += combinationSum4(nums, target-nums[i]);
        	}
        }
        return res;
    }
    */
    // Method-II:
    int combinationSum4(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	vector<int> dp(target+1, 0);
    	for(int i = 1; i <= target; i++){
    		for(int j = 0; j < nums.size(); j++){
    			if(nums[j] > i){		// when a element in nums is larger than target, ignore it
    				break;
    			}else if(nums[j] == i){	// when a element in nums equals to target
    				dp[i] += 1;
    			}else{		// if we want nums[j] to be the last one, we should have dp[target] = dp[target-nums[j]]
    				dp[i] += dp[i-nums[j]];
    			}
    		}
    	}
    	return dp[target];
    }


};