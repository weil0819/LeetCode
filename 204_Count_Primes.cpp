//===========================================================================================
// 204. Count Primes

// Description:

// Count the number of prime numbers less than a non-negative number, n.

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.
//===========================================================================================
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
private:
	bool check(int x){
		int end = (int)sqrt(x);
		for(int i = 2; i <= end; i++){
			if(x%i == 0){
				return false;
			}
		}	
		return true;	
	}
public:
	/**
	* Idea: straightforward method to design a function to decide the parameter is prime or not
	* and then traverse from 2 to n
	* 
	*/
    int countPrimes(int n) {
    	int output = 0;
        for(int i = 2; i < n; i++){
        	if(check(i)){
        		++output;
        	}
        }
        return output;
    }
};

int main(){
	Solution sn;
	cout<<sn.countPrimes(10)<<endl;
	return 0;
}