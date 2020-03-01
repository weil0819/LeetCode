//===========================================================================================
// 303. Range Sum Query - Immutable
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.
//===========================================================================================

class NumArray {
private:
	vector<int> _nums;

public:
    NumArray(vector<int> nums) {
        _nums = nums;
    }
    
    int sumRange(int i, int j) {
    	int sum = 0;
        for(int k = i; k <= j; k++){
        	sum += _nums[k];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


