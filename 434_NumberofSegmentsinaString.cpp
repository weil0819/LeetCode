class Solution {
public:
    /**
    * Idea: straightforward method to scan the string s
    * When s[i] != ' ' and the former element s[i-1] == ' ', this can be s segment
    * 
    */
    int countSegments(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                if(i == 0 || s[i-1] == ' '){
                    ++count;
                }
            }
        }

        return count;
    }
};