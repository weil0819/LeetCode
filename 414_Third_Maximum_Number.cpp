//===========================================================================================
// 414. Third Maximum Number
// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. 
// The time complexity must be in O(n).

// Example 1:
// Input: [3, 2, 1]

// Output: 1

// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]

// Output: 2

// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]

// Output: 1

// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.
//===========================================================================================
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: we set three flags to represent the maximum number, second maximum number, third maximum number
	* and then traverse the array and compare three times
	* 
	*/
    int thirdMax(vector<int>& nums) {
        long long fir = INT_MIN, sec = INT_MIN, thi = INT_MIN;
        fir = fir - 1;
        sec = sec - 1;
        thi = thi - 1;
        for(int i = 0; i < nums.size(); i++){
        	if(nums[i] > fir){
        		thi = sec;
        		sec = fir;
        		fir = nums[i];      		
        	}else if(nums[i] < fir && nums[i] > sec){
        		thi = sec;
        		sec = nums[i];
        	}else if(nums[i] < sec && nums[i] > thi){
        		thi = nums[i];
        	}
        }
        long long bound = INT_MIN;
        bound = bound -1;
        if(thi == bound){
        	return (int)fir;
        }else{
        	return (int)thi;
        }
    }
};

int main(){
	Solution sn;
	int a[] = {1,2,-2147483648};
	vector<int> nums(a, a+3);
	cout<<sn.thirdMax(nums)<<endl;
	return 0;
}

