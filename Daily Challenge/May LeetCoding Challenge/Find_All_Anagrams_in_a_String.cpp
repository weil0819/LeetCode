/*
Find All Anagrams in a String

@date: May 17, 2020

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    // Set up two pointers: begin and end
    // begin points to begin of the window
    // end points to end of the window
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int N = s.size(), M = p.size();
        if(M > N) return res;
        
        
        // Step-1: create a hashmap for shoter string p
        unordered_map<char, int> helper;
        for(int i = 0; i < M; i++) {
            helper[p[i]]++;
        }
        
        int begin = 0, end = 0;
        int cnt = helper.size();        
        while(end < N) {
            // Step-2: move "end" to the end of window
            char c = s[end];
            if(helper.find(c) != helper.end()) {
                helper[c]--;
                if(helper[c] == 0) --cnt;
            }
            ++end;
            
            while(cnt == 0) {
                // Step-3: recover hashmap 
                char c = s[begin];
                if(helper.find(c) != helper.end()) {
                    helper[c]++;
                    if(helper[c] > 0) ++cnt;
                }
                // Step-4: when (end-begin) == window, we find a anagram
                if(end - begin == M) {
                    res.push_back(begin);
                } 
                ++begin;
            }
        } 
        return res;
    }
};
