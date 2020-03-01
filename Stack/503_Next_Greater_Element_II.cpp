//===========================================================================================
// 503. Next Greater Element II
// Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.
// Note: The length of given array won't exceed 10000.
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: 1) firstly we can use a brute force method to solve this problem
	* time complexity is O(n^2) and space complexity is O(n)
	* 2) There is also a stack method, refer to https://leetcode.com/articles/next-greater-element-ii/
	* 
	*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        if(n == 0){
        	return res;
        }
        for(int i = 0; i < n; i++){
        	for(int j = 1; j < n; j++){
        		if(nums[(i+j)%n] > nums[i]){
        			res[i] = nums[(i+j)%n];
        			break;
        		}
        	}
        }
        return res;
    }
};

int main(){
	Solution sn;
	int a[] = {1,2,1};
	vector<int> nums(a, a+3);
	vector<int> res = sn.nextGreaterElements(nums);
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}