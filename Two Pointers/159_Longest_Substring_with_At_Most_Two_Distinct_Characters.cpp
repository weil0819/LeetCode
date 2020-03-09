/*
159. Longest Substring with At Most Two Distinct Characters -- Medium
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

@date: Mon 9 Mar. 2020

Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.

*/

class Solution {
public:
    // Use sliding window method
    // Use p and q record the begin and end
    // Use hashmap to record <char, #char>
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int N = s.size();
        if(N < 3) return N;
        
        int res = 0;
        int p = 0;      // begining position
        unordered_map<char,int> help;
        for(int i = 0; i < N; i++) {
            help[s[i]]++;
            while(help.size() > 2) {
                if(--help[s[p]] == 0) help.erase(s[p]);
                p++;
            }
            res = max(res, i-p+1);
        }
        return res;        
    }
};

