/*
Find All Duplicates in an Array

@date: Aug 6, 2020

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

class Solution {
public:
    // reverse nums[nums[i]-1] as negative
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        if(N == 0) return res;
        for(int i = 0; i < N; i++) {
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0) nums[idx] = -nums[idx];
            else res.push_back(abs(nums[i]));
        }
        return res;
    }
};
