//===========================================================================================
// 357. Count Numbers with Unique Digits

// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

// Example:
// Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

// Credits:
// Special thanks to @memoryless for adding this problem and creating all test cases.
//===========================================================================================
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	* Idea: 10^n - duplicated integers
	* n = 1, 10 non-duplicated integers
	* n = 2, 81+10=91 non-duplicated integers
	* n = 3, 9*9*8+9*9+10=
	*/
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        while(n >= 1){
        	int tmp = n, carry = 9, mul = 1;
        	while(tmp >= 1){
        		if(tmp == n || tmp == n-1){
        			mul *= carry;
        		}else{
        			mul *= carry-1;
        			carry--;
        		}
        		tmp--;
        	}
        	res += mul;
        	n--;
        }

        return res;
    }
};

int main(){
	Solution sn;
	cout<<sn.countNumbersWithUniqueDigits(3	)<<endl;
	return 0;
}