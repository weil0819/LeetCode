class Solution {
public:
    /**
    * Idea: n can recursively divisible by 3
    * 1.Find the maximum integer that is a power of 3 and check if it is a multiple of the given input. 
    * 1162261467 is 3^19,  3^20 is bigger than int, if 1162261467%3==0, that means n is power of 3
    * 2.
    */
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        int maxPowerThree = (int)pow(3, (int)(log(INT_MAX) / log(3)));
        return (maxPowerThree % n == 0);
    }
};