//==========================================================================================
// 238. Product of Array Except Self

// Given an array of n integers where n > 1, nums, 
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Solve it without division and in O(n).

// For example, given [1,2,3,4], return [24,12,8,6].

// Follow up:
// Could you solve it with constant space complexity? 
// (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
//==========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: we use two vector<int> to record the left and right products
	* that is, left[i] is the product from 0 to i-1, and right[i] is the product from n-1 to i-1
	* If we want to solve it with constant space complexity, we need to change two vector to two integers,
	* eg, given [1,2,3,4]
	* output[0]=1,left=1,output[3]=1,right=3
	* output[1]=1,left=2,output[2]=4,right=12
	* output[2]=8,left=6,output[1]=12,right=24
	* output[3]=6,left=24,output[0]=24,right=24
	* 
	*/
	// Method-I:
	/*
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i = 1; i < n; i++){
        	left[i] = left[i-1]*nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
        	right[i] = right[i+1]*nums[i+1];
        }
        vector<int> output(n, 0);
        for(int i = 0; i < n; i++){
        	output[i] = left[i]*right[i];
        }
        return output;
    }
    */

	// Method-II:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
    	int left = 1, right = 1;
    	vector<int> output(n, 1);
    	for(int i = 0; i < n; i++){
    		output[i] = output[i]*left;	
    		left = left*nums[i];
    		output[n-1-i] = output[n-1-i]*right;
    		right = right*nums[n-1-i];
    		cout<<"output["<<i<<"]="<<output[i]<<", "<<left<<", "<<"output["<<n-1-i<<"]="<<output[n-1-i]<<", "<<right<<endl;
    	}
    	return output;
    }
};


int main(){
	Solution sn;
	int a[] = {1,2,3,4};
	vector<int> nums(a, a+4);
	vector<int> output = sn.productExceptSelf(nums);
	for(int i = 0; i < output.size(); i++){
		cout<<output[i]<<endl;
	}
	return 0;
}