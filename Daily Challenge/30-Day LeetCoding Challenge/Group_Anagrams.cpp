/*
Group Anagrams
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3288/

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/


class Solution {
public:
    // Sorting each string and then compare them
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        
        unordered_map<string, vector<string> > help;    // hash map
        for(int i = 0; i < N; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(help.find(tmp) == help.end()) {
                vector<string> vec;
                vec.push_back(strs[i]);
                help.insert(make_pair(tmp, vec));
            } else {
                help[tmp].push_back(strs[i]);
            }
        }
        
        vector<vector<string> > res;
        for(auto p: help) {
            res.push_back(p.second);
        }
        
        return res;
    }
};


