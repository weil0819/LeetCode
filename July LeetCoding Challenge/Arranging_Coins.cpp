/*
Arranging Coins

@date: July 1, 2020

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

*/

class Solution {
public:
    // Math: (1+k)*k/2 <= n
    // k*k + k <= 2n
    // k*k + k + 1/4 <= 2n + 1/4
    // (k+1/2)^2 <= 2n+1/4
    // k <= sqrt(2n+1/4) - 1/2
    int arrangeCoins(int n) {
        return floor(sqrt(2*(double)n+0.25) - 0.5);        
    }
};
