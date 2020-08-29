/*
3Sum

@date: July 8, 2020

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
    // Tree pointers 
    // Sort 'nums' in ascending order
    // i, j=i+1, k=N-1
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int N = nums.size();
        if(N < 3) return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < N-2; i++) {
            if(nums[i] > 0) break;      // jump out
            if(i > 0 && nums[i] == nums[i-1]) continue ;    // same as previous one
            int j = i+1, k = N-1;
            while(j < k) {
                int a = nums[i], b = nums[j], c = nums[k];
                if(a + b + c == 0) {
                    vector<int> temp = {a, b, c};
                    res.push_back(temp);
                    while(j < k && nums[j+1] == nums[j]) j++;
                    while(k > j && nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                } else if(a + b + c < 0) {
                    while(j < k && nums[j+1] == nums[j]) j++;
                    j++;
                } else {
                    while(k > j && nums[k-1] == nums[k]) k--;
                    k--;
                }
            }
        }
        return res;
    }
};


