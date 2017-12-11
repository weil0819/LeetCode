class Solution {
public:
    /**
    * Idea: 1.straightforward compute the corresponding bit; 2. Bit Manipulation
    */
    bool hasAlternatingBits(int n) {
        int help = n%2;
        n = n/2;
        while(n != 0){           
            int tmp = n%2;
            if(tmp == help){                
                return false;
            }else{
                help = tmp;
            }
            n = n/2;
        }
        return true;
    }
};