/*
Add Binary

@date: July 19, 2020

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

*/

class Solution {
public:
    // from tail to head
    string addBinary(string a, string b) {
        int N = a.size(), M = b.size();
        string res = "";
        int i = N-1, j = M-1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return res;
    }
};

