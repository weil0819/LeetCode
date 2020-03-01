/*

22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
	/**
	* Idea: we use two integers p and q to record the remaining '(' and ')'
	* Initially, p = n, q = 0;
	* if(q > 0), we can insert one ')' or continue to insert one '(';
	* if(p > 0), we can insert one '(' and increase q
	* 
	*/
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        int p = n, q = 0;
        backtrack(res, str, p, q);
        return res;
    }

    void backtrack(vector<string>& res, string str, int p, int q){
    	if(p == 0 && q == 0){
    		res.push_back(str);
    		return ;
    	}
    	if(q > 0){
    		backtrack(res, str+")", p, q-1);
    	}
    	if(p > 0){
    		backtrack(res, str+"(", p-1, q+1);
    	}
    }
};