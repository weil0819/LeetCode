//===========================================================================================
// 20. Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: we set up a stack to record the left bracket
    * Once meeting a right bracket, we pop out a left one
    * 
    */
    bool isValid(string s) {
        stack<char> help;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                help.push(s[i]);
            }else{
                if(help.empty()){
                    return false;
                }
                char tmp = help.top();
                help.pop();
                if(s[i] == ')' && tmp != '('){
                    return false;
                }
                if(s[i] == ']' && tmp != '['){
                    return false;
                }
                if(s[i] == '}' && tmp != '{'){
                    return false;
                }
            }
        }
        return help.empty();
    }
};
