//===========================================================================================
// 665. Non-decreasing Array
// Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

// We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

// Example 1:
// Input: [4,2,3]
// Output: True
// Explanation: You could modify the first 
// 4
//  to 
// 1
//  to get a non-decreasing array.
// Example 2:
// Input: [4,2,1]
// Output: False
// Explanation: You can't get a non-decreasing array by modify at most one element.
// Note: The n belongs to [1, 10,000].
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: we directly traverse the array and compare array[i] and array[i+1]
	* If array[i] > array[i+1], we have two choices: 
	* one replaces array[i] with array[i+1]
	* another replaces array[i+1] with array[i] 
	* 
	*/
    bool checkPossibility(vector<int>& nums) {
    	int n = nums.size();
    	bool flag = false;
        for(int i = 0; i  < (n-1); i++){
        	if(nums[i] > nums[i+1]){
        		if(flag){
        			return false;
        		}
        		if(i > 0 && nums[i-1] > nums[i+1]){
        			nums[i+1] = nums[i];
        		}else{
        			nums[i] = nums[i+1];
        		}
        		flag = true;
        	}
        }
        return true;
    }
};

int main(){
	Solution sn;
	int a[] = {3,4,2,3};	//3,4,2,3(false) and 2,4,2,3(true) and 2,3,3,2,4(true)
	vector<int> nums(a, a+4);
	cout<<sn.checkPossibility(nums)<<endl;
	return 0;
}
