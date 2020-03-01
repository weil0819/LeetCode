/*
844. Backspace String Compare
https://leetcode.com/problems/backspace-string-compare/description/

*/

class Solution {
private:
    string getStr1(string& str){
        stack<char> S;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '#' && !S.empty()){
                S.pop();
            }else if(str[i] != '#'){
                S.push(str[i]);
            }
        }
        string res = "";
        while(!S.empty()){
            res = res + S.top();
            S.pop();
        }
        return res;
    }
    
    string getStr2(string& str){
        string res = "";
        int cnt = 0;
        for(int i = str.size()-1; i >= 0; i--){
            if(str[i] == '#') cnt++;
            else{
                if(cnt > 0) cnt--;
                else{
                    res += str[i];
                }
            }
        }
        return res;
    }
    
public:
    // Method-I: Using Stack to store each element, if encountering "#", pop out one element, O(n) and O(n)
    bool backspaceCompare(string S, string T) {
        // if(getStr1(S) == getStr1(T)) return true;
        // Method-II: O(n) and O(1)
        if(getStr2(S) == getStr2(T)) return true;
        return false;
    }

};

