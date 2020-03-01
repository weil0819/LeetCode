//===========================================================================================
// 686. Repeated String Match
// Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

// For example, with A = "abcd" and B = "cdabcdab".

// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

// Note:
// The length of A and B will be between 1 and 10000.
//===========================================================================================
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: If length(A) < length(B), repeatly add A
	* 
	*/
    int repeatedStringMatch(string A, string B) {
        int n = A.size(), m = B.size();
        string tmp = A;
        int len = (int)ceil(m*1.0/n);
        for(int i = 1; i < len; i++){
        	tmp.append(A);
        }
        for(int i = 0; i < tmp.size(); i++){
        	if(tmp[i] == B[0]){
        		bool flag2 = true;
        		for(int j = 1; j < m; j++){
        			if(tmp[i+j] != B[j]){
        				flag2 = false;
        				break;
        			}
        		}
        		if(flag2){
        			return len;
        		}
        	}
        }
        tmp.append(A);
         for(int i = 0; i < tmp.size(); i++){
        	if(tmp[i] == B[0]){
        		bool flag2 = true;
        		for(int j = 1; j < m; j++){
        			if(tmp[i+j] != B[j]){
        				flag2 = false;
        				break;
        			}
        		}
        		
        		if(flag2){
        			return (len+1);
        		}
        	}
        }
        return -1;               
    }
};

int main(){
	Solution sn;
	// ab cdabcdab cd
	cout<<sn.repeatedStringMatch("abcd", "cdabcdab")<<endl;
	return 0;
}