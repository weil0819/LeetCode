//===========================================================================================
// 168. Excel Sheet Column Title
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test cases.
//===========================================================================================
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: 1~~26+26*0, 27~~26+26*26, 27+26*26~~26+26*26+26*26*26,
	* it just likes a 26-arry number
	*  
	*/
    string convertToTitle(int n) {
    	char help[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
    	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    	string output = "";

    	while(n > 0){
    		n = n - 1;
    		char tmp = help[n%26];
    		output = tmp + output;
    		n = n/26;
    	}

 		return output;
    }
};

int main(){
	Solution sn;
	cout<<sn.convertToTitle(25)<<endl;
	return 0;
}