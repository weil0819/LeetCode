/*
Detect Capital

@date: Aug 3, 2020

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

*/

class Solution {
public:
    // Calculate the number of capitals
    bool detectCapitalUse(string word) {
        int N = word.size();
        int cnt = 0;    // the number of capitals
        for(int i = 0; i < N; i++) {
            if(word[i] <= 'Z' && word[i] >= 'A') {
                cnt++;
            }
        }        
        return (cnt == N) || (cnt == 1 && word[0] <= 'Z' && word[0] >= 'A') || (cnt == 0);
    }
};
