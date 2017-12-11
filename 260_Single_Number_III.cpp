//==========================================================================================
// 260. Single Number III

// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
// Find the two elements that appear only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//==========================================================================================

class Solution {
public:
	/**
	* Idea: bit manipulation
	* 1^2 = 3, 3^1 = 2, 2^3 = 1, 1^2 = 3, 3^5 = 6
    * @zhiqing_xiao's idea:
	* For this kind of question, we need to consider the XOR manipulation
    * Since there are two special numbers, we need to do it two passes:
    * In the first pass, we XOR all elements in the array, and get the XOR of the two numbers we need to find.
    * Note that since the two numbers are distinct, so there must be a set bit (that is, the bit with value '1') 
    * in the XOR result. Find out an arbitrary set bit (for example, the rightmost set bit).
    *
	* In the second pass, we divide all numbers into two groups, one with the aforementioned bit set, 
    * another with the aforementinoed bit unset. Two different numbers we need to find must fall into 
    * the two distrinct groups. XOR numbers in each group, we can find a number in either group.
    *
	*/
    vector<int> singleNumber(vector<int>& nums) {
        // compute the result of a^b, eg, 3^5=6
        int aXORb = 0;
        for(int i = 0; i < nums.size(); i++){
            aXORb = aXORb ^ nums[i];
        }
        // compute the last bit that a diff b, 011^101=110=>010
        int lastBit = (aXORb & (aXORb-1)) ^ aXORb;
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            // based on the last diff bit, we can divide nums into two groups
            if(nums[i] & lastBit){
                a = a ^ nums[i];
            }else{
                b = b ^ nums[i];
            }
        }
        vector<int> output;
        output.push_back(a);
        output.push_back(b);
        return output;
    }
};

