/*
Permutation in String

@date: May 18, 2020

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

*/

class Solution {
public:
    // Sliding window problem
    // Using Array to store <char, #char>
    bool checkInclusion(string s1, string s2) {
        int N = s1.size(), M = s2.size();
        if(N > M) return false;
        
        // Step-1: generate a hashmap for <char, #char> in s1
        vector<int> s1Helper(26, 0);      // store 26 alphabet in s1
        for(int i = 0; i < N; i++) {
            s1Helper[s1[i]-'a']++;
        }
        
        // Step-2: scan s2 and generate each hashmap for <char, #char> with len(s1)
        for(int i = 0; i <= M-N; i++) {
            vector<int> s2Helper(26, 0);    // store 26 alphabet in s2
            for(int j = 0; j < N; j++) {
                s2Helper[s2[i+j]-'a']++;
            }
            // Step-3: compare two hashmap to decide same or not
            if(match(s1Helper, s2Helper)) return true;
        }
        return false;
    }
    
private:
    bool match(vector<int>& H1, vector<int>& H2) {
        for(int i = 0; i < 26; i++) {
            if(H1[i] != H2[i]) return false;
        }
        return true;
    }
};

