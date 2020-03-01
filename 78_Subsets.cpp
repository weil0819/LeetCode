//===========================================================================================
// 78. Subsets

// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a backtracking problem
	* 
	*/
    vector<vector<int> > subsets(vector<int>& nums) {
        int start = 0;
        vector<vector<int> > res;
        vector<int> vec;
        backtrack(res, vec, nums, start);
        return res;
    }

    void backtrack(vector<vector<int> >& res, vector<int>& vec, vector<int> nums, int start){
    	res.push_back(vec);
    	for(int i = start; i < nums.size(); i++){
    		vec.push_back(nums[i]);
    		backtrack(res, vec, nums, i+1);
    		vec.pop_back();
    	}
    }
};