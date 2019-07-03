//===========================================================================================
// 650. 2 Keys Keyboard

// Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. 
// Output the minimum number of steps to get n 'A'.

// Example 1:
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
// Note:
// The n will be in the range [1, 1000].
//===========================================================================================
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	* Idea: this is a dynamic programming problem
	* we use dp[i] to represent the number of A after i steps
	* We have observations that 
    *               n=2 => steps=2, n=3 => steps=3, n=4 => steps=4, n=5 => steps=5
    *               n=6 => steps=5, n=7 => steps=7, n=8 => steps=6, n=9 => steps=6
	* we can analyse the special cases: n=6, n=8, n=9
    *               when n=6, C->P->P->C->P, due to 6=3*2, we get dp[3] first and then copy dp[3] 2 times 
    *               when n=8, C->P->C->P->C->P, due to 8=4*2, we get dp[4] first and then copy dp[4] 2 times 
    *               when n=9, C->P->P->C->P->P, due to 9=3*3, we get dp[3] first and then copy dp[3] 3 times
    *               That is, dp[i] should be the product of the first divisible integer and the times
	*/
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 2; i <= n; i++){
        	dp[i] = i;
        	for(int j = (i-1); j > 1; j--){            // here, dp[j] is the first divisible integer
        		if(i % j == 0){
        			dp[i] = dp[j] + (i/j);             // i/j is the times
        			break;
        		}
        	}
        }
        return dp[n];
    }
};

int main(){
	Solution sn;
	cout<<sn.minSteps(3)<<endl;
	return 0;
}
