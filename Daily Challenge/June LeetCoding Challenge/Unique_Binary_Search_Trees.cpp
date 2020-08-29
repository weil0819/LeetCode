/*
Unique Binary Search Trees

@date: June 25, 2020

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:
    // DP problem
    // Use any number as root, we can build a BST
    // And left side as left subtree and right side as right subtree
    // F(i, n), 1 <= i <= n: the number of unique BST, where the number i is the root of BST, and the sequence ranges from 1 to n.
    // ==> G(n) = F(1, n) + F(2, n) + ... + F(n, n) 
    // F(i, n) = G(i-1) * G(n-i), where	1 <= i <= n, and G(i-1) is left subtree and G(n-i) is right subtree
    // ==> G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
    // ====> dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] + ... + dp[i-1]*dp[0]
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;      // no tree node, we can have 1 empty BST
        dp[1] = 1;      // only one tree node, we can have 1 root BST
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1]*dp[i-j];        // F(i, n) = G(i-1) * G(n-i)
            }
        }
        return dp[n];
    }
};

