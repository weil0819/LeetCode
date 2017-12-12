class Solution {
public:
    /**
    * Idea: If it is true, s % substring == 0
    * We can iteratively decrease the length of substring from n/2 to 1
    * 
    */
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int len = n/2; len >= 1; len--){
            if(n % len == 0){
                // compare two substring
                // eg, ababab ==>we need check first four (abab)==last four (abab) ?
                if(s.substr(0, n-len) == s.substr(len, n)){
                    return true;
                }
            }
        }
        return false;
    }
};