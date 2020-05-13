/*
Single Element in a Sorted Array

@date: May 12, 2020

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.

*/

class Solution {
public:
    // Binary Search
    // O(logN)
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        int low = 0, high = N-1;
        
        while(low < high) {
            int mid = low + (high - low)/2;
            // odd position -- compare with left
            // even position -- compare with right
            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1])) {
                low = mid + 1;
            } else {
                high = mid;
            }            
        }
        return nums[low];
    }
};

