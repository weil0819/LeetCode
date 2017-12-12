//===========================================================================================
// 90. Subsets II

// Given a collection of integers that might contain duplicates, nums, 
// return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//===========================================================================================


class Solution {
public:
    /**
    * Idea: this is a backtracking problem
    * we can sort the candidate elements and don't consider the duplicated element when enumerating
    * Attention: the duplicated subsets mean same content no matter the order
    * 
    */
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        vector<int> vec;
        backtrack(res, vec, nums, 0);
        return res;
    }
    
    void backtrack(vector<vector<int> >& res, vector<int>& vec, vector<int>& nums, int start){
        res.push_back(vec);
        for(int i = start; i < nums.size(); i++){
            if(i==start || nums[i]!=nums[i-1]){
                vec.push_back(nums[i]);
                backtrack(res, vec, nums, i+1);
                vec.pop_back();
            }                
        }
    }
};

