/*
Remove K Digits

@date: May 13, 2020

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

class Solution {
public:
    // Using stack to store result
    // When stack top >= new element, pop out and push in
    string removeKdigits(string num, int k) {
        int N = num.size();
        if(N <= k) return "0";
        
        stack<char> helper;
        for(int i = 0; i < N; i++) {
            while(k > 0 && !helper.empty() && helper.top() > num[i]) {
                helper.pop();
                k--;
            }
            helper.push(num[i]);
        }
        
        // when k >0
        while(k-- > 0) {
            helper.pop();            
        }
        
        // generate result
        string res = "";
        while(!helper.empty()) {
            res = helper.top() + res;
            helper.pop();
        }
        // remove all the 0 at the head
        while(res.size() > 1 && res[0] == '0') {
            res = res.substr(1);
        }
        return res;
        
    }
};


