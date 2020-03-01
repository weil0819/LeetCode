//===========================================================================================
// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//===========================================================================================
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: just check whether needle is a substring of haystack?
	* Attention: when haystack or needle is empty, we should return 0
	*
	*/
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(n < m){
        	return -1;
        }
        if(n == 0 || m == 0){
        	return 0;
        }
        for(int i = 0; i < n; i++){
        	if(haystack[i] == needle[0]){
        		bool appear = true;
        		for(int j = 1; j < m; j++){
        			if(i+j > n || haystack[i+j] != needle[j]){
        				appear = false;
        				break;
        			}
        		}
        		if(appear){
        			return i;
        		}
        	}
        }
        return -1;
    }
};

int main(){
	Solution sn;
	cout<<sn.strStr("", "")<<endl;
	return 0;
}

