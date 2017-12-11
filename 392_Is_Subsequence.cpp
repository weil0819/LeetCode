//===========================================================================================
// 392. Is Subsequence

// Given a string s and a string t, check if s is subsequence of t.

// You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// s = "abc", t = "ahbgdc"

// Return true.

// Example 2:
// s = "axc", t = "ahbgdc"

// Return false.

// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

// Credits:
// Special thanks to @pbrother for adding this problem and creating all test cases.
//===========================================================================================
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* Idea: use two points to scan each element in s and t
	* we should traverse the longer array to compare with the shorter array
	* 
	*/
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if(m == 0){
        	return true;
        }
        if(n == 0){
        	return false;
        }
        int is = 0, it = 0;
        while(it < n){
        	if(t[it] == s[is]){
        		is++;
        		if(is == m){
        			return true;
        		}
        	}
        	it++;
        }
        return false;
    }
};

int main(){
	Solution sn;
	cout<<sn.isSubsequence("acb", "ahbgdc")<<endl;	// "" and "ahbgdc",  "acb" and "ahbgdc", "axc" and "ahbgdc"
	return 0;
}