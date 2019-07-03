//===========================================================================================
// 216. Combination Sum III

// Find all possible combinations of k numbers that add up to a number n, 
// given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


// Example 1:

// Input: k = 3, n = 7

// Output:

// [[1,2,4]]

// Example 2:

// Input: k = 3, n = 9

// Output:

// [[1,2,6], [1,3,5], [2,3,4]]
//===========================================================================================

class Solution {
public:
	/**
	* Idea: This is backtracking problem, we need select k elements among [1, 9]
	* Firstly, keep [1, ..., x] unchanged, change x, that is, we should change the last one each time
	*
	*/
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int> > res;
    	if(k > 9 || n > 45){
    		return res;
    	}
    	int start = 1, target = n;
    	vector<int> vec;
    	backtrack(res, vec, start, k, target);
    	return res;		        
    }

    void backtrack(vector<vector<int> >& res, vector<int> vec, int start, int k, int target){
    	if(target == 0 && vec.size() == k){
    		res.push_back(vec);
    		return ;
    	}
    	for(int i = start; i <= 9; i++){
    		vec.push_back(i);							// put i into vec, keep it unchanged
    		backtrack(res, vec, i+1, k, target-i);	    // compute the combinations of all (k-1) elements
    		vec.pop_back();								// recovery
    	}
    }
};
