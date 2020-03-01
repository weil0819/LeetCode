/*
974. Subarray Sums Divisible by K -- Medium
https://leetcode.com/contest/weekly-contest-119/problems/subarray-sums-divisible-by-k/

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> prefix_sum(K);           // store prefix sum
        prefix_sum[0] = 1;                   // 0 % K = 0, that means 0 is divisible by K
        
        int prefix = 0, res = 0;            // initialisation
        for(int i = 0; i < A.size(); i++) {
            int a = A[i];
            prefix = (prefix + a % K + K) % K;  // compute current prefix when adding A[i]
            res += prefix_sum[prefix];  // if some prefix appears more than zero, that means prefix sum is divisible by K
            prefix_sum[prefix]++;   // add 1
        }
        return res;
    }
};
