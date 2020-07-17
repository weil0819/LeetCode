/*
Reverse Words in a String

@date: July 15, 2020

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/

class Solution {
public:
    // reverse each word
    // reverse the whole string
    string reverseWords(string s) {
        int N = s.size();
        if(N == 0) return s;
        int i = 0, j = 0;
        int start = 0;
        int words = 0;
        while(i < N) {
            while(i < N && s[i] == ' ') i++;
            if(i == N) break;
            if(words > 0) {
                s[j] = ' ';
                j++;
            }
            start = j;
            while(i < N && s[i] != ' ') {
                s[j] = s[i];
                i++;
                j++;
            }
            reverse(s, start, j-1);
            words++;
        }
        s.resize(j);    // Resizes the string to a length of j characters
        reverse(s, 0, j-1);
        return s;
    }
private:
    void reverse(string& s, int start, int end) {
        while(start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};
