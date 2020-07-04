/*
Valid Parentheses

@date: July 4, 2020

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

*/

class Solution {
public:
    // stack-I: store left parentheses
    /*
    bool isValid(string s) {
        int N = s.size();
        if(N == 0) return true;
        
        stack<char> S;
        for(auto c: s) {
            if(c == '(' || c == '[' || c == '{') S.push(c);
            else {
                if(S.empty()) return false;
                char temp = S.top();
                S.pop();                
                if(c == ')' && temp != '(') return false;
                if(c == ']' && temp != '[') return false;
                if(c == '}' && temp != '{') return false;
            }
        }
        return S.empty();
    }
    */
    
    // stack-II: store right parentheses
    bool isValid(string s) {
        stack<char> S;
        for(auto c: s) {
            if(c == '(') S.push(')');
            else if(c == '[') S.push(']');
            else if(c == '{') S.push('}');
            else if(S.empty() || S.top() != c) return false;
            else S.pop();
        }
        return S.empty();
    }
    
};

