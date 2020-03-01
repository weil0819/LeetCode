/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
	/**
	* Idea: this is iterative problem
	* we need replace last round vector with new generated one
	* 
	*/
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        if(n == 0){
        	return res;
        }

        vector<string> cont;
        cont.push_back("0");
        cont.push_back("1");
        cont.push_back("abc");
        cont.push_back("def");
        cont.push_back("ghi");
        cont.push_back("jkl");
        cont.push_back("mno");
        cont.push_back("pqrs");
        cont.push_back("tuv");
        cont.push_back("wxyz");

        res.push_back("");
        for(int i = 0; i < n; i++){
        	vector<string> tmp;
        	string str = cont[digits[i]-'0'];
        	for(int j = 0; j < str.size(); j++){
        		for(int k = 0; k < res.size(); k++){
        			tmp.push_back(res[k]+str[j]);
        		}
        	}

        	res.swap(tmp);
        }
        return res;
    }
};



