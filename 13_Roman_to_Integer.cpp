//===========================================================================================
// 13. Roman to Integer

// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.
//===========================================================================================


class Solution {
public:
    /**
    * Idea: What is roman numeral?
    * I   V   X   L   C   D   M
    * 1   5   10  50  100 500 1000
    * For x=8, 5+1*3=VIII; x=200, 100+100=CC;
    * By following observations, 
    *                           1) 'I','X','C' is on the right of 'V','L','D','M', just add
    *                           2) 'I','X','C' is on the left of 'V','L','D','M', should minus the former
    * 
    * Therefore, we need to traverse each char of string, and sum the corresponding value
    * Attention: 1) in roman numberal, there is no 0; 2) in C++, the condition of switch should be integer or enumeration
    * 
    */
    int romanToInt(string s) {
        int n = s.size(), output = 0;
        for(int i = n-1; i >= 0; i--){
            char tmp = s[i];
            if(tmp == 'I'){
                output += (output >= 5 ? -1 : 1);
            }
            if(tmp == 'V'){
                output += 5;
            }
            if(tmp == 'X'){
                output += (output >= 50 ? -10 : 10);
            }
            if(tmp == 'L'){
                output += 50;
            }
            if(tmp == 'C'){
                output += (output >= 500 ? -100 : 100);
            }
            if(tmp == 'D'){
                output += 500;
            }
            if(tmp == 'M'){
                output += 1000;
            }
        }
        return output;
    }
};

