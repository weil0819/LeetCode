//===========================================================================================
// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: we should compare the occurrence number of each letter in s and t
    * Thus, we can use two unordered_map<char, int> to record the letter and its last occurance position
    * eg, aba and baa, when visiting the last element, we have <a,1> and <a,2> which is different
    * 
    */
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(int i = 0; i < s.size(); i++){
            if(s_map[s[i]] != t_map[t[i]]){
                return false;
            }
            s_map[s[i]] = i+1;
            t_map[t[i]] = i+1;
        }
        return true;
    }
};