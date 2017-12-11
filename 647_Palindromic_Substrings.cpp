//==========================================================================================
// 647. Palindromic Substrings

// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// Note:
// The input string length won't exceed 1000.
//==========================================================================================
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: First, we know each single char is a palindromic substring
	* Method-I: it is O(n^2) time cost. The idea is count the number of different palindromic substrings from their respective middle.
    * There are two cases: 
    *                   when we consider the substring s[i-j, ..., i+j], i is the middle index of the substring;
    *                   When we consider the substring s[i-1-j, ..., i+j], (i-1, i) is the middle index of the substring;
    * 
    * Method-II: Idea is start from each index and try to extend palindrome for both odd and even length
    *               s[0] s[1] s[2] s[3] s[4] s[5] s[6]
    *               when i = 3, we need to compare s[3] and s[3], s[2] and s[4], s[1] and s[5], s[0] and s[6], 
    *                                                           ie, {s[0] {s[1] {s[2] {s[3]} s[4]} s[5]} s[6]}
    *               when i = 3, we also need to compare s[3] and s[4], s[2] and s[5], s[1] and s[6], 
    *                                                           ie, s[0] {s[1] {s[2] {s[3] s[4]} s[5]} s[6]}
    * 
	*/
    // Method-I
    /*
    int countSubstrings(string s) {
    	int n = s.size(), count = 0;
        if(n == 0){
            return 0;
        }
    	for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n; j++){
                if(s[i-j] == s[i+j]){
                    ++count;
                }
            }
            for(int j = 0; i-1-j >= 0 && i+j < n; j++){
                if(s[i-1-j] == s[i+j]){
                    ++count;
                }
            }
        }
    	return count;        
    }*/

    // Method-II:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        if(n == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            checkPalindromic(s, i, i, count);
            checkPalindromic(s, i, i+1, count);
        }
        return count;
    }

    void checkPalindromic(string s, int left, int right, int& count){
    	int n = s.size();
    	while(left >= 0 && right < n && s[left] == s[right]){
    		++count;
    		left--;
    		right++;
    	}
    }
};


int main(){
	Solution sn;
	cout<<sn.countSubstrings("aaa")<<endl;
	return 0;
}