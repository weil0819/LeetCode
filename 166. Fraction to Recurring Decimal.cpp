/*

166. Fraction to Recurring Decimal
https://leetcode.com/problems/fraction-to-recurring-decimal/description/

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:

Input: numerator = 2, denominator = 1
Output: "2"

Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string ans = "";
        
        // positive or negative
        ans = ((numerator < 0) ^ (denominator < 0)) ? "-" : "";
        
        // int --> long long with only positive
        // int --> 4bytes, long --> 4bytes, long long --> 8bytes
        long long num = labs(numerator);
        long long den = labs(denominator);
        
        // integral part
        ans = ans + to_string(num / den);
        
        // compute the remainder
        long long remainder = num % den;
        if(remainder == 0) return ans;
        
        // remainder exists, compute fractional part
        ans = ans + ".";
        remainder *= 10;                            // 2*10=20
        unordered_map<long long, int> helper;       // <remainder, #pos of ans>
        while(remainder > 0){
            long long quotient = remainder / den;   // 20/3=6
            if(helper.find(remainder) != helper.end()){
                int pos = helper[remainder];        // pos=2
                ans.insert(pos, "(");               // "0.(6"
                ans = ans + ")";                    // "0.(6)"
                break;
            }
            helper[remainder] = ans.size();         // <6, 2>           
            ans = ans + to_string(quotient);        // ans = "0.6"
            remainder = (remainder % den) * 10;     // 20%3*10 = 20
        }
        return ans;             
    }
};