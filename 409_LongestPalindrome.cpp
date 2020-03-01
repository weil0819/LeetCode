/*

409. Longest Palindrome
https://leetcode.com/problems/longest-palindrome/description/

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    /**
    * Idea: first we should count the #element, 
    * and then pick up all element with #element=even and one element with #element=odd
    * 
    */
    int longestPalindrome(string s) {
        unordered_map<char, int> help;
        int n = s.size();
        for(int i = 0; i < n; i++){
            ++help[s[i]];
        }
        int output = 0;
        bool hasOdd = false;
        for(unordered_map<char, int>::iterator it = help.begin(); it != help.end(); ++it){
            if((it->second)%2 == 0){
                output += it->second;
            }else{
                hasOdd = true;
                if((it->second)/2 > 0){
                    output += (it->second)-1;
                }
            }
        }
        if(hasOdd){
            output += 1;
        }
        return output;
    }
};