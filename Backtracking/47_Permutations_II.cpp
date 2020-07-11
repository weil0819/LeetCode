/*
47. Permutations II

@date: July 11, 2020

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
public:
    // Backtracking
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        backtrack(res, nums, 0);
        return res;
    }
private:
    void backtrack(vector<vector<int> >& res, vector<int> nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return ;
        }
        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[start]) continue ;
            swap(nums[i], nums[start]);
            backtrack(res, nums, start+1);
            // swap(nums[i], nums[start]);
        }
    }
};
