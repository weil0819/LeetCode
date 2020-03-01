class Solution {
public:
    /**
    * Idea: 1.If num is perfect square, there will be a number n less than num, that n*n = num
    * We can use binary search to find n
    * Attention: we must use long not int
    * 2.Newton's method
    *  
    */
    bool isPerfectSquare(int num) {
        if(num <= 0){
            return false;
        }
        /*
        // need modified later
        long long low = 1, high = num;
        while(low <= high){
            long long mid = (low + high)/2;
            if(mid*mid == num){
                return true;
            }else if(mid*mid < num){
                low = mid + 1;
            }else{
                high = high - 1;
            }
        }
        return false;
        */

        int x = 1, tmp = 0;
        while(tmp != x){
            tmp = x;
            x = round((x + round(num / x)) / 2);
        }
        return x * x == num;

    }
};