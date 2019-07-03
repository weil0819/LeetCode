//===========================================================================================
// 334. Increasing Triplet Subsequence

// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Examples:
// Given [1, 2, 3, 4, 5],
// return true.

// Given [5, 4, 3, 2, 1],
// return false.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: we can set two points--p and q
	* p points to the first one
	* q points to the second one
	* if there exists a number > both p and q, return true
	* 
	*/
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
        	return false;
        }
        int p = INT_MAX,q = INT_MAX;
        for(int i = 0; i < n; i++){
        	if(nums[i] <= p){
        		p = nums[i];
        	}else if(nums[i] <= q){
        		q = nums[i];        		
        	}else{
        		return true;
        	}
        }
        return false;
    }
};