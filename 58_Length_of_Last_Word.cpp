//===========================================================================================
// 58. Length of Last Word
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: count the characters from tail to head until meeting a ' ' or arriving head
    * 
    */
    int lengthOfLastWord(string s) {
        int index = s.size()-1, output = 0;
        
        while(index >= 0){
            if(s[index] != ' '){
                ++output;
                index--;
            }else{
                if(output == 0 && index > 0){
                    index--;
                }else{
                    return output;
                }
            }
        }
        return output;
    }
};