//===========================================================================================
// 524. Longest Word in Dictionary through Deleting

// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by 
// deleting some characters of the given string. If there are more than one possible results, 
// return the longest word with the smallest lexicographical order. 
// If there is no possible result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]

// Output: 
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]

// Output: 
// "a"
// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: how to compute whether one string is substring of another
	* 
	*/
	bool isSubstring(string s1, string s2){
		int j = 0;
		for(int i = 0; i < s2.size() && j < s2.size(); i++){
			if(s1[j] == s2[i]){
				j++;
			}
		}
		return j == s2.size();
	}
    string findLongestWord(string s, vector<string>& d) {
    	int maxLen = 0, ind = -1;
        for(int i = 0; i < d.size(); i++){
        	if(isSubstring(d[i], s)){
        		if(d[i].size() > maxLen){
        			maxLen = d[i].size();
        			ind = i;
        		}else if(d[i].size() == maxLen){
        			if(d[i] < d[ind]){
        				ind = i;
        			}
        		}
        	}
        }

        return ind == -1 ? "" : d[ind];
    }
};