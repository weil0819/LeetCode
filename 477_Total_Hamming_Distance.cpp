//===========================================================================================
// 477. Total Hamming Distance

// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Now your job is to find the total Hamming distance between all pairs of the given numbers.

// Example:
// Input: 4, 14, 2

// Output: 6

// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
// showing the four bits relevant in this case). So the answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
// Note:
// Elements of the given array are in the range of 0 to 10^9
// Length of the array will not exceed 10^4.
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: 1) straightforward method
	* Time Limit Exceeded
    * 
    * 2) Inspired by @KJer
    * For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), 
    * and q numbers have 1 for LSB (put in set N).
    * There are 2 situations:
    * Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.
    * Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.
    * Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2
    * How many pairs are there in Situation 2?
    * We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).
    * The total possibilities is p × q = pq, which means
    * The total Hamming distance will get pq from LSB.
    *
    * 3) Inspired by @compton_scatter, For each bit position 1-32 in a 32-bit integer, 
    * we count the number of integers in the array 
    * which have that bit set. Then, if there are n integers in the array and k of them have a particular 
    * bit set and (n-k) do not, then that bit contributes k*(n-k) hamming distance to the total.
    *
	*/

    // Method-I:
    /*
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), output = 0;
        for(int i = 0; i < n-1; i++){
        	for(int j = i+1; j < n; j++){
        		output += hamDis(nums[i], nums[j]);
        	}
        }
        return output;
    }

    int hamDis(int a, int b){
    	int aXORb = a ^ b, output = 0;
    	while(aXORb != 0){                        // the number of "1" in aXORb == Hamming distance
    		aXORb = aXORb & (aXORb-1);            // remove one 1 each time
    		output++;
    	}
    	return output;
   	}
    */

    // Method-II:
    /*
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if(n < 2){
            return 0;
        }
        while(true){
            int p = 0, q = 0, zeroCount = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    ++zeroCount;
                }
                if(nums[i]%2 == 0){
                    p++;
                }else if(nums[i]%2 == 1){
                    q++;
                }
                nums[i] = nums[i] >> 1;
            }
            res = p*q;
            if(zeroCount == n){
                return res;
            }
        }
    }
    */

    // Method-III:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < 32; i++){
            int bitCount = 0;
            for(int j = 0; j < n; j++){
                bitCount += (nums[j] >> i) & 1;                
            }
            res += bitCount*(n - bitCount);
        }
        return res;
    }

};

int main(){
	Solution sn;
	int a[] = {4, 14, 2};
	vector<int> nums(a, a+3);
	cout<<sn.totalHammingDistance(nums)<<endl;
	return 0;
}