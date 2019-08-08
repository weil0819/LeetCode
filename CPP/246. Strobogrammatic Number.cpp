/*

246. Strobogrammatic Number -- Easy
https://leetcode.com/problems/strobogrammatic-number/ 

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false

*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> help{{'0','0'}, {'1','1'}, {'6','9'}, {'9','6'}, {'8','8'}};
        
        int l = 0, r = num.size()-1;
        while(l <= r) {
            if(help.find(num[l]) == help.end() || (help[num[l]] != num[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};



