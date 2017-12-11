//===========================================================================================
// 581. Shortest Unsorted Continuous Subarray

// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
// then the whole array will be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.
//===========================================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: by observating, if nums[i-1] < nums[i] and nums[i] > nums[i+1], nums[i] should be start point
	* if nums[i-1] > nums[i] and nums[i] < nums[i+1], nums[i] should be end point
	* 
	*/
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -1;
        for(int i = 0; i < n; i++){
        	if(i == 0 && nums[i] > nums[i+1]){
        		start = 0;
        	}else if(i == n-1 && nums[i-1] > nums[i]){
        		end = n-1;
        	}else if(i > 0 && i < n-1 && nums[i-1] < nums[i] && nums[i] > nums[i+1] && start == -1){
        		start = i;
        	}else if(i > 0 && i < n-1 && nums[i-1] > nums[i] && nums[i] < nums[i+1]){
        		end = i;
        	}
        }
        
        if(start == -1 && end == -1){
        	return 0;
        }else if(start != -1 && end == -1){
        	end = n-1;
        }
        return end-start+1;
    }
};



int main(){
	Solution sn;
	int a[] = {2,3,3,2,4};	// [2, 6, 4, 8, 10, 9, 15], [1,2,3,4], [1,3,2,2,2], [2,3,3,2,4]
	vector<int> nums(a, a+5);
	cout<<sn.findUnsortedSubarray(nums)<<endl;
	return 0;
}