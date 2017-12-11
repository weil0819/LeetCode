//===========================================================================================
// 491. Increasing Subsequences

// Given an integer array, your task is to find all the different possible increasing subsequences 
// of the given array, and the length of an increasing subsequence should be at least 2 .

// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
// Note:
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered 
// as a special case of increasing sequence.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a backtracking problem
	* 
	*/
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > res;
        if(n == 0){
        	return res;
        }
        vector<int> vec;
        backtrack(res, vec, nums, 0);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

    void backtrack(vector<vector<int> >& res, vector<int>& vec, vector<int>& nums, int start){
    	if(vec.size() >= 2){
    		res.push_back(vec);
    	}
    	for(int i = start; i < nums.size(); i++){
    		if(vec.size() == 0 || (vec.size() > 0 && nums[i] >= vec.back())){
    			vec.push_back(nums[i]);
    			backtrack(res, vec, nums, i+1);
    			vec.pop_back();
    		}   		
    	}
    }
};

