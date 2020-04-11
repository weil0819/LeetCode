/*
Single Number 
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/

class Solution {
public:
    // 1) XOR of a number with itself is 0
    // 2) XOR of a number with 0 is number itself
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        int res = nums[0];
        for(int i = 1; i < N; i++) {
            res ^= nums[i];
        }
        return res;
    }
};

