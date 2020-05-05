/*
First Unique Character in a String

@date: May 5, 2020

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/


class Solution {
public:
    // Using hashmap to record the <char, #char>
    int firstUniqChar(string s) {
        int N = s.size();
        if(N == 0) return -1;
        
        unordered_map<char, int> helper;
        for(int i = 0; i < N; i++) {
            helper[s[i]]++;
        }
        
        for(int i = 0; i < N; i++) {
            if(helper[s[i]] == 1) return i;
        }
        return -1;
    }
};