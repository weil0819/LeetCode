/*
Find the Duplicate Number

@date: June 25, 2020

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

class Solution {
public:
    // Binary Search
    // 
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int low = 1, high = N-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            int cnt = 0;
            for(int i = 0; i < N; i++) {
                if(nums[i] <= mid) ++cnt;
            }
            // Normally, there should be 'mid' elements less than 'mid'
            // But if more than 'mid', duplicated element should be not larger than 'mid'
            // otherwise not
            if(cnt <= mid) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

