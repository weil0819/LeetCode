//===========================================================================================
// 482. License Key Formatting

// Now you are given a string S, which represents a software license key which we would like to format. 
// The string S is composed of alphanumerical characters and dashes. 
// The dashes split the alphanumerical characters within the string into groups. 
// (i.e. if there are M dashes, the string is split into M+1 groups). 
// The dashes in the given string are possibly misplaced.

// We want each group of characters to be of length K (except for possibly the first group, which could be shorter, 
// 	but still must contain at least one character). 
// To satisfy this requirement, we will reinsert dashes. 
// Additionally, all the lower case letters in the string must be converted to upper case.

// So, you are given a non-empty string S, representing a license key to format, and an integer K. 
// And you need to return the license key formatted according to the description above.

// Example 1:
// Input: S = "2-4A0r7-4k", K = 4

// Output: "24A0-R74K"

// Explanation: The string S has been split into two parts, each part has 4 characters.
// Example 2:
// Input: S = "2-4A0r7-4k", K = 3

// Output: "24-A0R-74K"

// Explanation: The string S has been split into three parts, each part has 3 characters except the first part as 
// it could be shorter as said above.
// Note:
// The length of string S will not exceed 12,000, and K is a positive integer.
// String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
// String S is non-empty.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: traverse string from tail to head
	* if encountering a dash, we ignore it, and we insert a dash for each K chars
	* 
	*/
    string licenseKeyFormatting(string S, int K) {
        int n = S.size();
        if(n == 0){
        	return S;
        }
        string res = "";
        string tmp = "";
        for(int i = n-1; i >=0; i--){
        	if((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')){
                char c = toupper(S[i]);
        		tmp = c + tmp;
        	}else if(S[i] >= '0' && S[i] <= '9'){
        		tmp = S[i] + tmp;
        	}
        	if(tmp.size() == K){
                if(res != ""){
                    res = tmp + "-" + res;
                }else{
                    res = tmp + res;
                }        		
        		tmp.clear();
        	}
        }
        if(tmp.size() != 0 && res != ""){
        	res = tmp + "-" + res;
        }else if(tmp.size() != 0 && res == ""){
            res = tmp + res;
        }
        return res;
    }
};