//===========================================================================================
// 39. Combination Sum

// Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]
//===========================================================================================

class Solution {
private:
    void backtrack(vector<vector<int> >& res, vector<int> candidates, vector<int> vec, int start, int target){
    	if(target == 0){
    		res.push_back(vec);
    		return ;
    	}

    	for(int i = start; i < candidates.size() && target >= candidates[i]; i++){// target must be larger than candidates[1]
    		vec.push_back(candidates[i]);
    		backtrack(res, candidates, vec, i, target-candidates[i]);	// here we consider the repeated current one
    		vec.pop_back();
    	}
    }

public:
	/**
	* Idea: this is backtracking problem
	* The special part is that each number can be repeated, so we need to recosider current number not the next one
	* Attention: the candidates array should be sorted in ascending order
	* 
	*/
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	vector<vector<int> > res;
    	vector<int> vec;
    	int start = 0; 
    	backtrack(res, candidates, vec, start, target);
    	return res;
    }
};
