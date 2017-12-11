//===========================================================================================
// 421. Maximum XOR of Two Numbers in an Array

// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

// Could you do this in O(n) runtime?

// Example:

// Input: [3, 10, 5, 25, 2, 8]

// Output: 28

// Explanation: The maximum result is 5 ^ 25 = 28.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: 1)straightforward method: compute the XOR value for each pair, O(n^2)
	* 2)we have observations that a^b=c ==> c^b=a and c^a=b
	* 
	*/
    int findMaximumXOR(vector<int>& nums) {
        int res = INT_MIN, n = nums.size();
        if(n < 2){
        	return 0;
        }
        for(int i = 0; i < n-1; i++){
        	for(int j = i+1; j < n; j++){
        		int tmp = nums[i] ^ nums[j];
        		res = tmp > res ? tmp : res;
        	}
        }
        return res;
    }
};