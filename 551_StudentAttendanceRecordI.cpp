class Solution {
public:
    /**
    * Idea: just scan the string
    *  
    */
    bool checkRecord(string s) {    
        int numA = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                ++numA;
                if(numA > 1){
                    return false;
                }
            }else if(s[i] == 'L'){
                if(i < s.size()-2 && s[i+1] == 'L' && s[i+2] == 'L'){
                    return false;
                }
            }
        }
        return true;
    }
};