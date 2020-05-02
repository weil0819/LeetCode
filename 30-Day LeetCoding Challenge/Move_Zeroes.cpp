/*
Move Zeroes
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

class Solution {
public:
    // two pointers
    // one for interation
    // one for non-zero element
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return;
        int p = 0;
        for(int i = 0; i < N; i++) {
            if(nums[i] != 0) {
                nums[p++] = nums[i];
            }
        }
        while(p < N) {
            nums[p++] = 0;
        }
    }
};


