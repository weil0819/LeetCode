//===========================================================================================
// 46. Permutations

// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: it is a backtracking problem, keep all elements before start and then compute the permutation
	* and then move start point
	* swap-->do-->swap
	* 
	*/
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int start = 0;
        backtrack(res, nums, start);
        return res;
    }

    void backtrack(vector<vector<int> >& res, vector<int>& nums, int start){
    	if(start == nums.size()-1){
    		res.push_back(nums);
    	}
    	for(int i = start; i < nums.size(); i++){
    		swap(nums[start], nums[i]);
    		backtrack(res, nums, start+1);
    		swap(nums[i], nums[start]);
    	}
    }
};

int main(){
	Solution sn;
	int a[] = {1,2,3};
	vector<int> nums(a, a+3);
	vector<vector<int> > res = permute(nums);
	for(int i = 0; i <res.size(); i++){
		for(int j = 0; j < res[0].size(); j++){
			cout<<res[i][j]<<endl;
		}
	}
	return 0;
}