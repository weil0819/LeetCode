//===========================================================================================
// 290. Word Pattern
// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: use two hashmap to record the char or string and the position
    * unordered_map<char, int> and unordered_map<string, int>
    * We must make sure that the #segments should be consistent
    * 
    */
    bool wordPattern(string pattern, string str) {
        if(pattern == ""){
            return false;
        }
        unordered_map<char, int> help_pattern;
        unordered_map<string, int> help_str;
        int start = 0;
        for(int i = 0; i < pattern.size(); i++){           
            string tmp = "";
            int j;
            for(j = start; j < str.size(); j++){
                if(str[j] != ' '){
                    tmp += str[j];
                }else{
                    start = j + 1;
                    break;
                }
            }
            // #segments of pattern is not equal to that of str
            if(i == (pattern.size()-1) && j != str.size()){
            	return false;
            }
            if(i != (pattern.size()-1) && j == str.size()){
            	return false;
            }
            if(help_pattern[pattern[i]] == 0 && help_str[tmp] == 0){
                help_pattern[pattern[i]] = i+1;
                help_str[tmp] = i+1;
            }else if(help_pattern[pattern[i]] != 0 && help_str[tmp] != 0){
                if(help_pattern[pattern[i]] != help_str[tmp]){
                    return false;
                }
            }else{
                return false;
            }                  
        }
        return true;
    }
};