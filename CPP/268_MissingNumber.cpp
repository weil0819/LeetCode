class Solution {
public:
    /**
    * Idea: 1.Bit Manipulation: The basic idea is to use XOR operation. 
    * We all know that a^b^b =a, 
    * which means two xor operations with the same number will eliminate the number and reveal the original number.
    * 2.we observe that the sum of difference between i and nums[i] + n = x
    */
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int output = n;
        for(int i = 0; i < n; i++){
            //output += i - nums[i];
            output = output ^ i ^ nums[i];
        }
        return output;
    }
};