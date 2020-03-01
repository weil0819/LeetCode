/*

336. Palindrome Pairs
https://leetcode.com/problems/palindrome-pairs/description/

Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]

Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

*/

class Solution {
private:
    bool isPalindrome(string& str){
        int l = 0, r = str.size()-1;
        while(l < r){
            if(str[l++] != str[r--]) return false;
        }
        return true;
    }
    
    void reverseStr(string& str){
        int l = 0, r = str.size()-1;
        while(l < r){
            char tmp = str[l];
            str[l] = str[r];
            str[r] = tmp;
            l++;
            r--;
        }
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        int n = words.size();
        if(n < 2) return ans;
        
        unordered_map<string, int> UM; 
        for(int i = 0; i < n; i++) UM.insert(make_pair(words[i], i));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= words[i].size(); j++){

                string str1 = words[i].substr(0, j);
                string str2 = words[i].substr(j);
                
                if(isPalindrome(str1)){

                    reverseStr(str2);

                    if(UM.find(str2) != UM.end() && UM.find(str2)->second != i){
                        vector<int> tmp;
                        tmp.push_back(UM.find(str2)->second);
                        tmp.push_back(i);
                        ans.push_back(tmp);                        
                    }

                    reverseStr(str2);
                }
                

                if(str2.size() > 0 && isPalindrome(str2)){

                    reverseStr(str1);

                    if(UM.find(str1) != UM.end() && UM.find(str1)->second != i){
                        vector<int> tmp;
                        tmp.push_back(i);
                        tmp.push_back(UM.find(str1)->second);                        
                        ans.push_back(tmp);                         
                    }

                    reverseStr(str1);                    
                }
            }
        }
        return ans;
    }
};