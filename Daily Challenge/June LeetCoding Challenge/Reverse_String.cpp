/*
Reverse String

@date: June 5, 2020

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

*/

class Solution {
public:
    // Two pointers 
    // we just need to scan half 's'
    void reverseString(vector<char>& s) {
        int N = s.size();
        if(N == 0) return ;
        
        for(int i = 0; i < N/2; i++) {
            char temp = s[i];
            s[i] = s[N-i-1];
            s[N-i-1] = temp;            
        }
    }
};

