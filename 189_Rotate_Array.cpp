//===========================================================================================
// 189. Rotate Array
// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

// [show hint] 
// Hint:
// Could you do it in-place with O(1) extra space?

// Related problem: Reverse Words in a String II

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: use a help vector to store the prefix elements
	* O(n) time complexity and O(n) space complexity 
	* https://leetcode.com/articles/rotate-array/
	*/
    void rotate(vector<int>& nums, int k) {
        vector<int> help(nums);
        int n = nums.size();
        for(int i = 0; i < n; i++){
        	nums[(i+k)%n] = help[i];
        }       
    }
};

int main(){
	Solution sn;
	int a[] = {1,2,3,4,5,6,7};
	vector<int> nums(a, a+7);
	sn.rotate(nums, 11);				// [1,2,3,4,5,6] 11
	return 0;
}