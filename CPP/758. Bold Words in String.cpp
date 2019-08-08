/*

758. Bold Words in String -- Easy 
https://leetcode.com/problems/bold-words-in-string/ 

Given a set of keywords words and a string S, make all appearances of all keywords in S bold. 
Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". 
Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters. 

*/

class Solution {
public:
    string boldWords(vector<string>& words, string S) { 
        int N = S.size();
        vector<bool> mask(N, false);        // if corresponding position is in keyword, make it true 
        
        // generate mask
        for(auto word: words) {
            int pos = 0;
            // find word in S from pos index
            while((pos = S.find(word, pos)) != string::npos) {
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
            res.append(1,S[i]);   // insert original char            
        }       
        
        // exception case -- the last char is in word
        if(flag) res.append("</b>");
        
        return res;
    }
};

