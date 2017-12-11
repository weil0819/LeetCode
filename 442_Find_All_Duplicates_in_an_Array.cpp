//==========================================================================================
// 442. Find All Duplicates in an Array

// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements that appear twice in this array.

// Could you do it without extra space and in O(n) runtime?

// Example:
// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [2,3]
//==========================================================================================
#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
	/**
	* Idea: [4,3,2,7,8,2,3,1] ==> [4,3,2,-7,8,2,3,1]         
	* 							  ==> [4,3,-2,-7,8,2,3,1] ==> [4,-3,-2,-7,8,2,3,1]
	* 							  ==> [4,-3,-2,-7,8,2,-3,1] ==> [4,-3,-2,-7,8,2,-3,-1]
	* 							  ==> [4,-3,-2,-7,8,2,-3,-1] ==> [-4,-3,-2,-7,8,2,-3,-1]
	* we need to flag nums[abs(nums[i])-1] as its negative value
	* 
	*/
    vector<int> findDuplicates(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> output;
        for(int i = 0; i < n; i++){
        	int ind = abs(nums[i])-1;
        	if(nums[ind] > 0){
        		nums[ind] = -nums[ind];
        	}else{
        		output.push_back(abs(nums[i]));
        	}
        }
        return output;
    }
};

int main(){
	Solution sn;
	int a[] = {4,3,2,7,8,2,3,1};
	vector<int> nums(a, a+8);
	vector<int> output = sn.findDuplicates(nums);
	for(int i = 0; i < output.size(); i++){
		cout<<output[i]<<endl;
	}
	return 0;
}
