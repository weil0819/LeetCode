class Solution {
public:
    /**
    * Idea: 1.straightforward method to scan the array
    * 2.math method to directly compute the result
    * (1+2+3+...+x) = n ==> (1+x)x/2 = n ==> x = -0.5 + sqrt(2n+0.25)
    */
    int arrangeCoins(int n) {
        /*
        int sum = n, count = 0;
        for(int i = 1; i <= n; i++){
            if(sum < i){
                return count;
            }else{
                ++count;
                sum -= i;
            }
        }
        return count;
        */
        return floor(-0.5 + sqrt((double)2*n+0.25));
    }
};