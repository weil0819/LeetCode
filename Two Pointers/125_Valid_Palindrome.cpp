//===========================================================================================
// 125. Valid Palindrome

// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.
//===========================================================================================

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: for a alphanumeric character x, x-'a' < 32 or x-'A' < 32
	* A-Z's ASCII is from 65 to 90, a-z's ASCII is from 97 to 122
	* In c++, we have 
	* 				 int isalnum ( int c );	// Check if character is alphanumeric
	* 				 int tolower ( int c ); // Convert uppercase letter to lowercase
	* 				 int toupper ( int c ); // Convert lowercase letter to uppercase
	* 
	*/
    bool isPalindrome(string s) {
        int n = s.size();
        if(n <= 1){
        	return true;
        }
        int i = 0, j = n-1;
        while(i < j){
        	while(!isalnum(s[i])){
        		i++;
        	}
        	while(!isalnum(s[j])){
        		j--;
        	}
        	if(i < j && tolower(s[i]) != tolower(s[j])){
        		return false;
        	}else{
        		i++;
        		j--;
        	}
        }
        return true;
    }
};

int main(){
	Solution sn;
	cout<<sn.isPalindrome("A man, a plan, a canal: Panama")<<endl;
	return 0;
}
