/*
Valid Palindrome

@date: Aug 3, 2020

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

*/

class Solution {
public:
    // Two pointers from head and tail
    bool isPalindrome(string s) {
        int N = s.size();
        if(N == 0) return true;
        
        int p = 0, q = N-1;
        while(p < q) {
            while(p < q && isalnum(s[p]) == 0) p++;
            while(p < q && isalnum(s[q]) == 0) q--;
            if(tolower(s[p]) != tolower(s[q])) return false;
            else {
                p++;
                q--;
            }
        }
        return true;
    }
};

