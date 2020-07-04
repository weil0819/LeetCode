/*
Missing Number

@date: July 3, 2020

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/

class Solution {
public:
    // a^b^b = a
    // nums[0]^0^nums[1]^1^nums[2]^2...nums[n-1]^n-1^n
    // there will be 2n-1 elements
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int res = N;
        for(int i = 0; i < N; i++) {
            res = res ^ i ^ nums[i];
        }
        return res;
    }
};
