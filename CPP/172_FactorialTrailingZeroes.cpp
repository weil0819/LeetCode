class Solution {
public:
    /**
    * Idea: n<5=>0, 5<=n<10=>1, 10<=n<15=>2, 15<=n<20=>3, 20<=n<25=>4, 25<=n<30=>6
    * 25=5*5, so 25!=25/5+25/5/5=6
    * Firstly, we need to count how many multiples of 5, 
    * and then how many multiples of 25, next 5*5*5, 5*5*5*5
    * Attention: we must use long long not int in for clause
    */
    /*
    int trailingZeroes(int n) {
        int output = 0;
        while(n/5 > 0){
            output += n/5;
            n /= 5;            
        }
        return output;        
    }
    */
    int trailingZeroes(int n){
        if(n < 5){
            return 0;
        }
        int count = 0;
        for(long long i = 5; n/i > 0; i*=5){
            count += n/i;
        }
        return count;
    }
};