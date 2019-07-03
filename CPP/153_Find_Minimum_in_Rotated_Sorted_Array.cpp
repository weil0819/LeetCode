//==========================================================================================
// 153. Find Minimum in Rotated Sorted Array

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.
//==========================================================================================

class Solution {
public:
	/**
	* Idea: this kind of serach problem can be adopted binary search 
	* case1: nums[mid] >= nums[low] => low = mid+1
	* case2: nums[mid] < nums[start] => high = mid
	* Attention: we should consider the special case that nums[low] < nums[high] => return nums[low]
	*/
    int findMin(vector<int>& nums) {
    	int n = nums.size();
        int low = 0, high = n-1;
        while(low < high){
        	if(nums[low] < nums[high]){
        		return nums[low];
        	}
        	int mid = low + (high-low)/2;
        	if(nums[mid] >= nums[low]){
        		low = mid+1;
        	}else{
        		high = mid;
        	}
        }
        return nums[low];
    }
};
