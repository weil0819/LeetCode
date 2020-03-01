//==========================================================================================
// 338. Counting Bits

// Given a non negative integer number num. 
// For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
// Credits:
// Special thanks to @ syedee for adding this problem and creating all test cases.
//==========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: we have n&(n-1) = make n move right on step, that means minus one "1"
	* thus, we know that output[n&(n-1)] + 1 = output[n]
	* Since we have computed output[n&(n-1)] before output[n]
	* 
	*/
    vector<int> countBits(int num) {
    	vector<int> output(num+1, 0);
    	output[0] = 0;
        for(int i = 1; i <= num; i++){
        	output[i] = output[i&(i-1)] + 1;
        }
        return output;
    }
};

int main(){
	Solution sn;
	vector<int> res = sn.countBits(5);
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<endl;
	}
	return 0;
}