/*
Subsets

@date: July 11, 2020

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    // backtracking
    // single backtrack recursive function
    // consider number by number as head
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> sub;
        backtrack(res, sub, nums, 0);
        return res;
    }
private:
    void backtrack(vector<vector<int> >& res, vector<int>& sub, vector<int>& nums, int start) {
        res.push_back(sub); // []->[1]->[1,2]->[1,2,3]->[1,3]->[2]->[2,3]->[3]
        for(int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);     // assume nums[i] as head
            backtrack(res, sub, nums, i+1);
            sub.pop_back(); // [1,2]->[1]->[1]->[]->[2]
        }
    }
};
