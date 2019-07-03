//==========================================================================================
// 462. Minimum Moves to Equal Array Elements II

// Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, 
// where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

// You may assume the array's length is at most 10,000.

// Example:

// Input:
// [1,2,3]

// Output:
// 2

// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):

// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
//==========================================================================================
#include <iostream>			// cout
#include <vector>			// vector
#include <stdlib.h> 		// abs
#include <algorithm>		// sort
using namespace std;

class Solution {
public:
	/**
	* Idea: we firstly should sort the array and then find the middle one
	* we guess this middle number should be the final value
	* such like Best Meeting Point
	*
	*/
    int minMoves2(vector<int>& nums) {
    	int n = nums.size();
    	if(n <= 1){
    		return 0;
    	}

        sort(nums.begin(), nums.end());
        int mid = nums[n/2], output = 0;
        for(int i = 0; i < n; i++){
        	output += abs(nums[i]-mid);
        }
        return output;
    }
};



int main(){
	Solution sn;
	int a[] = {1,2,3};
	vector<int> nums(a, a+3);
	cout<<sn.minMoves2(nums)<<endl;
	return 0;
}