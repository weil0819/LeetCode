//===========================================================================================
// 378. Kth Smallest Element in a Sorted Matrix

// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// Example:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// return 13.
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n2.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: player can choose the first or the last integer in the reamining array
	* Inspired by @YUANGAO1023,
	* Solution 2 : Binary Search
	* The key point for any binary search is to figure out the "Search Space". 
	* For me, I think there are two kind of "Search Space" -- index and range(the range from the smallest number to the biggest number). 
	* Most usually, when the array is sorted in one direction, we can use index as "search space", 
	* when the array is unsorted and we are going to find a specific number, we can use "range".
	* Let me give you two examples of these two "search space"
	* 	1)index -- A bunch of examples -- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ ( the array is sorted)
	* 	2)range -- https://leetcode.com/problems/find-the-duplicate-number/ (Unsorted Array)
	* The reason why we did not use index as "search space" for this problem is the matrix is sorted in two directions, 
	* we can not find a linear way to map the number and its index.
	* 
	*/
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	int n = matrix.size(), m = matrix[0].size();
    	int low = matrix[0][0], high = matrix[n-1][m-1]+1;		//[low, high)
    	while(low < high){
    		int mid = low + (high-low)/2;
    		int count = 0, j = matrix[0].size()-1;					// count how many integers smaller than mid
    		for(int i = 0; i < n; i++){
    			while(j >= 0 && matrix[i][j] > mid){
    				j--;
    			}
    			count += (j+1);
    		}
    		if(count < k){							// if there are less than k integers smaller than mid, we should increase mid
    			low = mid+1;
    		}else{
    			high = mid;
    		}
    	}
    	return low;        
    }
};