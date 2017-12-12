//===========================================================================================
// 89. Gray Code

// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
// A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: G(i) = i^ (i/2)
	* 
	*/
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < 1<<n; i++){
        	res.push_back(i ^ i>>1);
        }
        return res;
    }


    // convert an unsigned binary number to reflected binary Gray code
    unsigned int binaryToGray(unsigned int num){
    	return (num >> 1) ^ num;
    }

	// convert a reflected binary Gray code number to a binary number
    unsigned int grayToBinary(unsigned int num){
    	unsigned int mask;
    	for(mask = num >> 1; mask != 0; mask = mask >> 1){
    		num = num ^ mask;
    	}
    	return num;
    }

};

int main(){
	Solution sn;
	vector<int> res = sn.grayCode(2);
	cout<<sn.binaryToGray(2)<<endl;
	return 0;
}