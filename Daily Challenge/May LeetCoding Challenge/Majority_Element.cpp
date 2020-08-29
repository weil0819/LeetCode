/*
Majority Element

@date: May 6, 2020

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

class Solution {
public:
    // Boyer-Moore Majority Vote Algorithm
    // http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
    // current candidate and a counter
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        
        int curCand = INT_MIN;
        int counter = 0;
        
        for(int i = 0; i < N; i++) {
            // If the counter is 0, 
            // we set the current candidate to e and we set the counter to 1.
            if(counter == 0) {
                curCand = nums[i];
                counter = 1;
            } else {    // If the counter is not 0, 
                if(nums[i] == curCand) {    // we increment or decrement the counter 
                    counter++;              // according to whether e is the current candidate.
                } else {
                    counter--;
                }
            }
        }
        return curCand;        
    }
};


