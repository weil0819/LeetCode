/*
186. Reverse Words in a String II -- Medium
https://www.leetfree.com/problems/reverse-words-in-a-string-ii.html

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Update (2017-10-16):
We have updated the function signature to accept a character array, so please reset to the default code definition by clicking on the reload button above the code editor. Also, Run Code is now available!

*/

class Solution {
private:
    void reverse(string& s, int i, int j){
        while(i < j){
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }        
    }

public:
    void reverseWords(string &s) {
        int n = s.size();
        if(n == 0) return ;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ' ' || i == n-1){
                end = i==n-1 ? n-1 : i-1;
                reverse(s, start, end);
                start = i+1;
            }
        }
        reverse(s, 0, n-1);
    }
};