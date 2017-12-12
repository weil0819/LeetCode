//===========================================================================================
// 26. Remove Duplicates from Sorted Array
// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: Since it is a sorted array, we can straightforward visit the array
    * 
    */
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), output = 1;
        if(n <= 1){
            return n;
        }        
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                nums[output] = nums[i];
                ++output;
            }
        }
        return output;
    }
};