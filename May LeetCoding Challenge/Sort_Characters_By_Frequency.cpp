/*
Sort Characters By Frequency

@date: May 22, 2020

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/


class Solution {
public:
    // Using a hashmap to record the <char, #char>
    // Iterate hashmap and erase visited ones
    string frequencySort(string s) {
        int N = s.size();
        if(N == 0) return s;
        
        unordered_map<char, int> helper;
        for(int i = 0; i < N; i++) helper[s[i]]++;
        
        string res = "";
        while(!helper.empty()) {
            int cnt = 0;
            char temp;
            for(auto p: helper) {
                if(p.second > cnt) {
                    cnt = p.second;
                    temp = p.first;
                }                
            }
            for(int i = 0; i < cnt; i++) {
                res += temp;
            }
            helper.erase(temp);
        }
        return res;
    }
};

