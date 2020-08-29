/*
Ransom Note

@date: May 3, 2020

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int N = ransomNote.size(), M = magazine.size();        
        if(N > M) return false;
        
        unordered_map<char, int> helper;
        for(auto s: magazine) {
            helper[s]++;
        }
        
        for(auto s: ransomNote) {
            if(helper.find(s) != helper.end()) {
                helper[s]--;
                if(helper[s] < 0) {
                    return false;
                }
            } else {
                return false;
            }             
        }
        return true;
    }
};

