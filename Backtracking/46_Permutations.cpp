/*
46. Permutations

@date: July 11, 2020

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
public:
    // Backtracking
    // 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0);
        return res;
    }
private:
    void backtrack(vector<vector<int> >& res, vector<int>& nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return ;
        }
        // permute num[start..end]
        // invariant: num[0..start-1] have been fixed
        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backtrack(res, nums, start+1);
            swap(nums[i], nums[start]); // reset
        }
    }
};
