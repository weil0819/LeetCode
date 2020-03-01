//==========================================================================================
// 77. Combinations

// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//==========================================================================================

class Solution {
public:
	/**
	* Idea: this is a backtracking problem
	* 
	*/
    vector<vector<int> > combine(int n, int k) {
        int start = 1;
        vector<int> vec;
        vector<vector<int> > res;
        backtrack(res, vec, start, k, n);
        return res;
    }

    void backtrack(vector<vector<int> >& res, vector<int> vec, int start, int k, int n){
    	if(vec.size() == k){
    		res.push_back(vec);
    		return ;
    	}
    	for(int i = start; i <= n; i++){
    		vec.push_back(i);
    		backtrack(res, vec, i+1, k, n);
    		vec.pop_back();    		
    	}
    }
};

