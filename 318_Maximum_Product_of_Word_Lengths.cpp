//===========================================================================================
// 318. Maximum Product of Word Lengths

// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
// where the two words do not share common letters. You may assume that each word will contain only lower case letters. 
// f no such two words exist, return 0.

// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".

// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".

// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.

// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test cases.
//===========================================================================================
// bool cmp(string str1, string str2){
// 	return str1.size() > str2.size();
// }

class Solution {
public:
	/**
	* Idea: sort the array in descending order and compare them
	* 
	*/
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0;
        if(n == 0){
        	return 0;
        }
        sort(words.begin(), words.end());
        for(int i = n-1; i >= 0; i--){
        	for(int j = (i-1); j >= 0; j--){
        		string str1 = words[i], str2 = words[j];
        		if(isSharedCom(str1, str2)){
        			int tmp = str1.size()*str2.size();
        			if(tmp > res){
        				res = tmp;
        			}
        		}
        	}
        }
        return res;
    }

    bool isSharedCom(string str1, string str2){
    	unordered_set<char> helper;
    	for(int i = 0; i < str1.size(); i++){
    		if(helper.find(str1[i]) == helper.end()){
    			helper.insert(str1[i]);
    		}
    	}
    	for(int i = 0; i < str2.size(); i++){
    		if(helper.find(str2[i]) != helper.end()){
    			return false;
    		}
    	}  
    	return true;  	
    }
};