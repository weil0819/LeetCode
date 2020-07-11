/*
90. Subsets II

@date: July 11, 2020

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

class Solution {
public:
    // Backtracking
    // if duplicated, ignore it
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        backtrack(res, sub, nums, 0);
        return res;
    }
private:
    // enumerate from 1: [1]->[1,2]->[1,2,2]----->[1,2]
    void backtrack(vector<vector<int> >& res, vector<int>& sub, vector<int>& nums, int start) {
        res.push_back(sub);
        for(int i = start; i < nums.size(); i++) {
            // when having pop out, i != start, consider duplication
            if(i > start && nums[i] == nums[i-1]) continue ;
            sub.push_back(nums[i]);
            backtrack(res, sub, nums, i+1);
            sub.pop_back();
        }
    }
};
