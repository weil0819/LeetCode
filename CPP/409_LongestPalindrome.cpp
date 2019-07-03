class Solution {
public:
    /**
    * Idea: first we should count the #element, 
    * and then pick up all element with #element=even and one element with #element=odd
    * 
    */
    int longestPalindrome(string s) {
        unordered_map<char, int> help;
        int n = s.size();
        for(int i = 0; i < n; i++){
            ++help[s[i]];
        }
        int output = 0;
        bool hasOdd = false;
        for(unordered_map<char, int>::iterator it = help.begin(); it != help.end(); ++it){
            if((it->second)%2 == 0){
                output += it->second;
            }else{
                hasOdd = true;
                if((it->second)/2 > 0){
                    output += (it->second)-1;
                }
            }
        }
        if(hasOdd){
            output += 1;
        }
        return output;
    }
};