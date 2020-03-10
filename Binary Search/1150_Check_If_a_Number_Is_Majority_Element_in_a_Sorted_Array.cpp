/*
1150. Check If a Number Is Majority Element in a Sorted Array -- Easy
https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

@date: Tue 10 Mar. 2020

Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.

A majority element is an element that appears more than N/2 times in an array of length N.

 

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: 
The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.
Example 2:

Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: 
The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.
 

Note:

1 <= nums.length <= 1000
1 <= nums[i] <= 10^9
1 <= target <= 10^9

*/

class Solution {
public:
    // use binary search to find the first target position
    // decide based on first and first+N/2
    bool isMajorityElement(vector<int>& nums, int target) {
        int N = nums.size();
        
        int first = getTarget(nums, target);        
        int last = first + N/2;
        if(last < N && nums[first] == target && nums[last] == target) return true;
            
        return false;
    }
    
    int getTarget(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;        
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] >= target) {
                r = m-1;
            }else l = m+1;
        }
        return l;
    }
};
