/*
Counting Bits

@date: May 28, 2020

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

class Solution {
public:
    // Bit manipulation
    // n&(n-1) will reduce one '1' from n
    // so, we can regard that the number of '1' in n is equal to that in n&(n-1) + 1
    // i.e., bits(5) = bits(5&4) + 1 = bits(4) + 1
    vector<int> countBits(int num) {        
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; i++) {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};

