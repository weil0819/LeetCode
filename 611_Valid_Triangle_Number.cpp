//===========================================================================================
// 611. Valid Triangle Number

// Given an array consists of non-negative integers, your task is to count the number of triplets 
// chosen from the array that can make triangles if we take them as side lengths of a triangle.

// Example 1:
// Input: [2,2,3,4]
// Output: 3
// Explanation:
// Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Note:
// The length of the given array won't exceed 1000.
// The integers in the given array are in the range of [0, 1000].
//===========================================================================================

class Solution {
public:
	/**
	* Idea: for a triangle(a,b,c), we have a+b>c && a>=b>=c
	* we first sort the array and set one value as c, traverse all pairs before c as (a,b)
	* 
	*/
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0;
        for(int i = 2; i < n; i++){
        	int low = 0, high = i-1;
        	while(low < high){
        		if(nums[low] + nums[high] > nums[i]){
        			cnt = cnt + (high-low);
        			high--;
        		}else{
        			low++;
        		}        		
        	}
        }
        return cnt;
    }
};