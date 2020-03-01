/*
227. Basic Calculator II
https://leetcode.com/problems/basic-calculator-ii/description/

*/

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0) return 0;
        
        stack<int> S;               // O(n) and O(n)
        int ans = 0, tmp = 0;
        char sign = '+';            // store the lastest sign
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                tmp = tmp*10 + s[i]-'0';
            }
            if((!isdigit(s[i]) && !isspace(s[i])) || (i == n-1)){
                if(sign == '+') S.push(tmp);
                if(sign == '-') S.push(-tmp);
                if(sign == '*') {               
                    int num = S.top();
                    S.pop();
                    S.push(num*tmp);
                }
                if(sign == '/') {
                    int num = S.top();
                    S.pop();
                    S.push(num/tmp);
                }
                sign = s[i];            // sign will be used for the next digit
                tmp = 0;
            }
        }
        while(!S.empty()) {
            ans += S.top();
            S.pop();
        }
        return ans;
    }
};

