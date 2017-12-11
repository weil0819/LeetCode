//===========================================================================================
// 532. K-diff Pairs in an Array

// Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
// Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

// Example 1:
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// Example 2:
// Input:[1, 2, 3, 4, 5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// Example 3:
// Input: [1, 3, 1, 5, 4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).
// Note:
// The pairs (i, j) and (j, i) count as the same pair.
// The length of the array won't exceed 10,000.
// All the integers in the given input belong to the range: [-1e7, 1e7].
//===========================================================================================
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/**
	* Idea: use a unordered_map<int, int> to record the k-diff pairs
	* Attention: k should be not less than 0
	* k=0 and k!= 0 should be considered separately
	* 
	*/
    int findPairs(vector<int>& nums, int k) {
    	if(nums.size() == 0 || k < 0){
    		return 0;
    	}
 		unordered_map<int, int> help;
 		for(int i = 0; i < nums.size(); i++){
 			++help[nums[i]];
 		}
 		int output = 0;
 		if(k == 0){
 			for(unordered_map<int, int>::const_iterator it = help.begin(); it != help.end(); ++it){
 				if(it->second > 1){
 					++output;
 				}
 			}			
 		}else{
 			for(unordered_map<int, int>::iterator it = help.begin(); it != help.end(); ++it){
 				int tmp = it->first;
 				if(help.find(tmp-k) != help.end()){
 					++output;
 				}
 			} 					
 		}
 		return output; 	
    }
};

int main(){
	Solution sn;
	int a[] = {1,2,3,4,5};
	vector<int> nums(a, a+5);
	cout<< sn.findPairs(nums, 4)<<endl;
	return 0;
}

