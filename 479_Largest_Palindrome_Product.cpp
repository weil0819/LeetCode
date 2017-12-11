//===========================================================================================
// 479. Largest Palindrome Product

// Find the largest palindrome made from the product of two n-digit numbers.

// Since the result could be very large, you should return the largest palindrome mod 1337.

// Example:

// Input: 2

// Output: 987

// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

// Note:

// The range of n is [1,8].
//===========================================================================================
#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: compute the minimum and maximum n-digit numbers
	* and then build a function to check whether current produce is palindrome or not
	* 
	*/
    int largestPalindrome(int n) {
        long long low = pow(10, n-1);
        long long high = pow(10, n)-1;
        long long maxP = (long long)INT_MIN;
        for(long long i = high; i >= low; i--){
        	for(long long j = i; j >= low; j--){
        		long long tmp = i*j;
        		if(check(tmp)){ 
        			low = j; 
        			cout<<"tmp = "<<tmp<<", i = "<<i<<", j = "<<j<<endl;    			
        			if(tmp > maxP){
        				maxP = i*j;
        			}
        			break;
        		}
        	}
        }
        return (int)(maxP%1337);
    }

    bool check(long long x){
    	long long y = 0, tmp = x;
    	while(tmp > 0){
    		y = y*10 + tmp%10;
    		tmp = tmp/10;
    	}
    	if(y == x){
    		return true;
    	}else{
    		return false;
    	}
    }
};


int main(){
	Solution sn;
	cout<<sn.largestPalindrome(5)<<endl;		// 2=>987, 3=>123, 5=>677
	return 0;
}