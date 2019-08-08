/*

616. Add Bold Tag in String -- Easy 
https://leetcode.com/problems/add-bold-tag-in-string/ 

Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap 
the substrings in s that exist in dict. If two such substrings overlap, 
you need to wrap them together by only one pair of closed bold tag. 
Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"

Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"

Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].

*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int N = s.size();
        vector<bool> mask(N, false);        // if corresponding position is in keyword, make it true 
        
        // generate mask
        for(auto word: dict) {
            int pos = 0;
            // find word in S from pos index
            while((pos = s.find(word, pos)) != string::npos) {
                // all char in word should be masked
                for(int i = 0; i < word.size(); i++) {
                    mask[pos+i] = true;
                }
                pos += 1;
            }
        }
        
        // add bold
        int flag = 0;
        string res = "";
        for(int i = 0; i < N; i++) {
            if(flag == 0) {     
                if(mask[i]) {   // can insert "<b>"
                    res.append("<b>");
                    flag = 1;
                }
            }else {
                if(!mask[i]) {  // can insert "</b>"
                    res.append("</b>");
                    flag = 0;
                }
            }
            // res.push_back(S[i]);
            res.append(1,s[i]);   // insert original char            
        }       
        
        // exception case -- the last char is in word
        if(flag) res.append("</b>");
        
        return res;
    }
};


