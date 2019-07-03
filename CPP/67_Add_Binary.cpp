//===========================================================================================
// 67. Add Binary
// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".
//===========================================================================================

class Solution {
public:
	/**
	* Idea: set a carry and add two string from tail to head
	* 
	*/
    string addBinary(string a, string b) {
        int carry = 0;
        string output = "";
        int i = a.size()-1, j = b.size()-1;
        while(i >= 0 || j >= 0){
        	int sum = 0;
        	if(i >= 0){
        		sum += a[i] -'0';
                i--;
        	}
        	if(j >= 0){
        		sum += b[j] - '0';
                j--;       		
        	}
        	sum += carry;
        	if(sum >= 2){
        		carry = 1;
        		sum -= 2;
        	}else{
        		carry = 0;
        	}
        	output = to_string(sum) + output;
        }
        if(carry == 1){
            output = to_string(carry) + output;
        }
        return output;
    }
};