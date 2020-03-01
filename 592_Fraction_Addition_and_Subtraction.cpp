//===========================================================================================
// 592. Fraction Addition and Subtraction

// Given a string representing an expression of fraction addition and subtraction, 
// you need to return the calculation result in string format. The final result should be irreducible fraction. 
// If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. 
// So in this case, 2 should be converted to 2/1.

// Example 1:
// Input:"-1/2+1/2"
// Output: "0/1"
// Example 2:
// Input:"-1/2+1/2+1/3"
// Output: "1/3"
// Example 3:
// Input:"1/3-1/2"
// Output: "-1/6"
// Example 4:
// Input:"5/3+1/3"
// Output: "2/1"
// Note:
// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has format ±numerator/denominator. 
// If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, 
// where the numerator and denominator of each fraction will always be in the range [1,10]. 
// If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1,10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
//===========================================================================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
   /**
    * Idea: Just scan the string sequently
    * we need to get how to calculate the GCD between two integers
    * 
    */
    string fractionAddition(string expression) {
        int n  = expression.size();
        int numerator = 0, denominator = 1, start = 0;
        bool flag = true;
        if(expression[start] == '-'){
            start = 1;
            flag = false;
        }
        string s1 = ""; 
        int up = 0, down = 0;
        for(int i = start; i < n; i++){
            if(expression[i] != '/' && expression[i] != '+' && expression[i] != '-'){
                s1 = s1 + expression[i]; 
            }else if(expression[i] == '/'){
                up = flag == true ? stoi(s1) : -stoi(s1);
                s1.clear();
            }else if(expression[i] == '+' || expression[i] == '-'){
                down = stoi(s1);
                s1.clear();
                int gcd = GCD(denominator, down);
                numerator = numerator*(down/gcd) + up*(denominator/gcd);
                denominator = denominator*down/gcd;                

                if(expression[i] == '-'){
                    flag = false;
                }else if(expression[i] == '+'){
                    flag = true;
                }
            }
            if(i == n-1){
                down = stoi(s1);
                s1.clear();
                int gcd = GCD(denominator, down);
                numerator = numerator*(down/gcd) + up*(denominator/gcd);
                denominator = denominator*(down/gcd);                 
            }
        }

        string res = "";
        int gcd = GCD(abs(numerator), denominator);
        res = res + to_string(numerator/gcd) + "/" + to_string(denominator/gcd);
        return res;
    }

    int GCD(int a, int b ){ 
        return (b == 0) ? a : GCD(b, a % b); 
    }

};


int main(){
	Solution sn;
	cout<<sn.fractionAddition("-7/3")<<endl;        //"7/2+2/3-3/4"=>"41/12",  "-7/3"==>"-7/3"
	return 0;
}