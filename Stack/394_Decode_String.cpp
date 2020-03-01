//===========================================================================================
// 394. Decode String
// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
// is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, 
// square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits 
// and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
//===========================================================================================

class Solution {
public:
	/**
	* Idea: 1)this is a dynamic programming problem
	* For a sub-problem, we create a new function which contains parameters--string and returns a string
	* 
	* 2)we can use a stack<string> to record the encoded_string and a stack<int> to record the k
	* 
	*/
    string decodeString(string s) {
        stack<string> encoded_string;
        stack<int> k;
        int i = 0;
        string res = "";
        while(i < s.size()){
        	if(s[i] >= '1' && s[i] <= '9'){
        		int cnt = s[i] - '0';
        		while((i+1) < s.size() && s[i+1] >= '1' && s[i+1] <= '9'){
        			cnt = cnt*10 + (s[i+1]-'0');
        			i++;
        		}
        		k.push(cnt);
        	}else if(s[i] == '['){
        		encoded_string.push(res);
        		res = "";        		
        	}else if(s[i] == ']'){
        		string str = encoded_string.top();
        		encoded_string.pop();
        		int num = k.top();
        		k.pop();
        		while(num > 0){
        			str = str + str;
        			num--;
        		}
        		res = res + str;
        	}else{
        		res = res + s[i];
        	}
        	i++;
        }
        return res;
    }
};
