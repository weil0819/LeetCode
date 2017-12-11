class Solution {
public:
    /**
    * Idea:1.straightforward calculate its binary version, and count #1
    * 2.right shift n by one step each time, and & 1
    * 3.Each time of "n &= n - 1", we delete one '1' from n, until n == 0
    * 
    */
    int hammingWeight(uint32_t n) {
        int output = 0;
        while(n != 0){
            output += n&1;
            n >>= 1;
        }
        return output;
    }
};