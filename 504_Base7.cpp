class Solution {
public:
    /**
    * Idea: continuously divided by 7
    * Attention: we should differ the positive and negative number
    */
    string convertToBase7(int num) {
        string prefix;
        if(num > 0){
            prefix = "";
        }else if(num == 0){
            return "0";
        }else{
            prefix = "-";
        }       
        string postfix = "";
        while(num != 0){
            postfix = to_string(abs(num%7)) + postfix;
            num = num/7;
        }
        return prefix + postfix;        
    }
};