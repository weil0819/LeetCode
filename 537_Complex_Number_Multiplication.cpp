//===========================================================================================
// 537. Complex Number Multiplication

// Given two strings representing two complex numbers.

// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

// Example 1:
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
// Example 2:
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
// Note:

// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. 
// And the output should be also in this form.
//===========================================================================================
#include <iostream>
#include <stdlib.h> 
#include <string.h>
using namespace std;

class Solution {
public:
	/**
	* Idea: A = aa+bbi, B = cc+ddi
	* A*B = aa*cc + (-bb*dd) + (aa*dd+bb*cc)i
	* 
	*/
    string complexNumberMultiply(string a, string b) {
        string aa = "", bb = "", cc = "", dd = "";
        bool flag1 = true, flag2 = true;
        for(int i = 0; i < a.size(); i++){
        	if(a[i] != '+' && flag1){
        		aa = aa + a[i];
        	}else if(a[i] == '+'){
        		flag1 = false;
        	}else if(a[i] != 'i' && !flag1){
        		bb = bb + a[i];
        	}
        }
        for(int i = 0; i < b.size(); i++){
        	if(b[i] != '+' && flag2){
        		cc = cc + b[i];
        	}else if(b[i] == '+'){
        		flag2 = false;
        	}else if(b[i] != 'i' && !flag2){
        		dd = dd + b[i];
        	}
        }
        int t1 = atoi(aa.c_str())*atoi(cc.c_str()) + (-1)*(atoi(bb.c_str())*atoi(dd.c_str()));
        int t2 = atoi(aa.c_str())*atoi(dd.c_str()) + atoi(bb.c_str())*atoi(cc.c_str());
        string output = "";
        output = output + to_string(t1) + "+" + (to_string(t2)+"i");
        return output;
    }
};


int main(){
	Solution sn;
	cout<< sn.complexNumberMultiply("1+1i", "1+1i")<<endl;
	return 0;
}

