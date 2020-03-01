//==========================================================================================
// 540. Single Element in a Sorted Array

// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. 
// Find this single element that appears only once.

// Example 1:
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: [3,3,7,7,10,11,11]
// Output: 10
// Note: Your solution should run in O(log n) time and O(1) space.
//==========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: bit manipulation
	* 2^2 = 10^10 = 00 
	* 0^3 = 00^11 = 11 = 3
	* 2^3 = 10^11 = 01 = 1
	* Since it requires O(log n) time and the given is a sorted array, we should adopt binary search
	* 1,1,2,3,3,4,4,8,8   		3,3,7,7,10,11,11
	* 0,1,2,3,4,5,6,7,8			0,1,2,3,4, 5, 6
	* 
	*/
    int singleNonDuplicate(vector<int>& nums) {
    	
    	// O(n) time cost
        // for(int i = 0; i < nums.size()-1; i = i+2){
        // 	int tmp = nums[i] ^ nums[i+1];
        // 	if(tmp != 0){
        // 		return nums[i];
        // 	}
        // }
        // return nums[nums.size()-1];

		// O(log n) time cost
        if(nums.size() == 1){
        	return nums[0];
        }
        int low = 0, high = nums.size()-1;
        while(low < high){
        	int mid = (low+high)/2;			// 4
        	if(mid%2 == 1){
        		mid--;						
        	}
        	if(nums[mid] != nums[mid+1]){	// 3!=4
        		high = mid;					// 4
        	}else{
        		low = mid+2;
        	}
        }
        return nums[low];
    }
};

int main(){
	Solution sn;
	int a[] = {3,3,7,7,10,11,11};
	vector<int> nums(a, a+7);
	cout<<sn.singleNonDuplicate(nums)<<endl;
	return 0;
}