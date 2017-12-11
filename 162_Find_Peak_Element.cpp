//===========================================================================================
// 162. Find Peak Element

// A peak element is an element that is greater than its neighbors.

// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that num[-1] = num[n] = -∞.

// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

// Note:
// Your solution should be in logarithmic complexity.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: Since it requires log complexity, we shoudl consider the binary search method
	* 
	*/
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
        	return 0;
        }
        int low = 0, high = n-1;
        while(low < high){
        	int mid = (low+high)/2;
        	int midR = mid+1;
        	if(nums[mid] > nums[midR]){
        		high = mid;
        	}else{
        		low = midR;
        	}
        }
        return low;
    }
};
