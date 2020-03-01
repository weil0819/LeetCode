/*
966. Vowel Spellchecker -- Medium
https://leetcode.com/contest/weekly-contest-117/problems/vowel-spellchecker/

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), 
then the query word is returned with the same case as the case in the wordlist.

Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"

Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, 
it matches a word in the wordlist (case-insensitive), then the query word is returned 
with the same case as the match in the wordlist.

Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], 
queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 

Note:

1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
All strings in wordlist and queries consist only of english letters.

*/

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        if(queries.size() == 0) return {};
        set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap_map, vow_map;     // <new_string, org_string>
        for(auto w: wordlist) {
            string w_low = tolow(w), w_vow = tovow(w);
            cap_map.insert(make_pair(w_low, w));
            vow_map.insert(make_pair(w_vow, w));
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            if (words.count(queries[i])) continue;  // exactly match
            string q_low = tolow(queries[i]), q_vow = tovow(queries[i]);
            if (cap_map.count(q_low)) {             // Capitalization match     
                queries[i] = cap_map[q_low];
            } else if (vow_map.count(q_vow)) {      // Vowel match
                queries[i] = vow_map[q_vow];
            } else {
                queries[i] = "";
            }
        }
        return queries;
    }
    
private:
    string tolow(string w) {
        for(auto& c: w){
            c = tolower(c);
        }
        return w;
    }
    
    string tovow(string w) {
        w = tolow(w);
        for(auto& c: w){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '#';
            }
        }
        return w;
    }
};


