/*
Backspace String Compare
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?


*/


class Solution {
public:
    // Scan the two strings from end to begin.
    // Compare the two final text.
    bool backspaceCompare(string S, string T) {
        if(getText(S) == getText(T)) return true;
        return false;
    }
private:
    string getText(string str) {
        string res = "";
        int cnt = 0;        // how many '#' after current char
        for(int i = str.size()-1; i >= 0; i--) {
            if(str[i] == '#') ++cnt;
            else {
                if(cnt > 0) --cnt;
                else res = str[i] + res;
            }
        }        
        return res;
    }
};

