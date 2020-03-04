/*
316. Remove Duplicate Letters -- Hard
https://leetcode.com/problems/remove-duplicate-letters/

@date: Mon 2 Mar. 2020 

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"
Example 2:

Input: "cbacdcbc"
Output: "acdb"

*/

class Solution {
public:
    // Use hashmap to record <char, #char>
    // Use hashmap to record <char, visited>
    // Scan "s" if s[i] < res[j] && hashmap[j]>0, replace j with i
    string removeDuplicateLetters(string s) {
        int N = s.size();
        if(N == 0) return s;
        string res = "";
        unordered_map<char,int> help, visited;
        for(auto c: s) {
            help[c]++;
        }
        for(auto c: s) {
            help[c]--;
            if(visited[c]) continue ;
            while(!res.empty() && help[res.back()] > 0 && c < res.back()) {
                visited[res.back()] = 0;    // unvisited
                res.pop_back();             // pop the last one char
            }
            res += c;
            visited[c] = 1;                 // visited
        }
        return res;
    }
};

