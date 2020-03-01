//===========================================================================================
// 7. Reverse Integer
// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

// click to show spoilers.
// Have you thought about this?
// Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

// Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 
// How should you handle such cases?

// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
//===========================================================================================
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: we should compare the reverse integer with INT_MAX and INT_MIN
	* so, we should store the result with long long 
	* range of int is -2^31~2^31-1
	* range of long is -2^31~2^31-1
	* range of long long is -2^63~2^63-1
	* 
	*/
    int reverse(int x) {
        long long output = 0;
        while(x != 0){
        	int tmp = x%10;
        	output = output*10 + tmp;
        	x = x/10;
        }
        if(output > INT_MAX || output < INT_MIN){
        	return 0;
        }
        return (int)output;
    }
};

int main(){
	Solution sn;
	cout<<sn.reverse(-123)<<endl;
	return 0;
}
