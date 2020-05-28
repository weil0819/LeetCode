/*
Contiguous Array

@date: May 26, 2020

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    // Suppose 0 in "nums" as -1
    // so, sum of contiguous subarray will be 0
    // Using a hashmap to store <sum, position>
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        
        int res = 0, sum = 0;
        unordered_map<int, int> helper;
        // initialize the map and set the position as -1
        helper.insert(make_pair(0, -1));  
        
        for(int i = 0; i < N; i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if(helper.find(sum) != helper.end()) {
                res = max(res, i-helper[sum]);
            } else {
                helper[sum] = i;
            }            
        }
        return res;
    }
};
