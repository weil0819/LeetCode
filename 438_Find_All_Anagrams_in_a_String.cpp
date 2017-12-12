//===========================================================================================
// 438. Find All Anagrams in a String
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//===========================================================================================
#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
    * Idea: we can use a unordered_map<char, int> to record char and its number in p
    * and then visit s, when it comes to a letter in p, we compare the following p.size()-1 letters
    * 
    */
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> help;
        int m = p.size(), n = s.size();
        vector<int> output;
        if(n < m){
            return output;
        }
        for(int i = 0; i < m; i++){
            ++help[p[i]];
        }
        for(int i = 0; i <= n-m; i++){
            if(help[s[i]] > 0 && check(s, help, i, m)){
                output.push_back(i);
            }
        }
        return output;
    }

    bool check(string s, unordered_map<char, int> help, int i, int m){
        for(int j = i; j < (i+m); j++){
            if(help.find(s[j]) == help.end()){
                return false;
            }
            --help.find(s[j])->second;
        }
        for(unordered_map<char, int>::iterator it = help.begin(); it != help.end(); ++it){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sn;
    vector<int> res = sn.findAnagrams("cbaebabacd", "abc");
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}