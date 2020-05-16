/*
Shuffle an Array
https://leetcode.com/explore/featured/card/top-interview-questions-easy/98/design/670/

@date: May 15, 2020

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

*/

class Solution {
private:
    vector<int> nums;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        // How to generate shuffle array?
        // keep nums[2] unchanged, and then swap nums[0] with nums[1] or nums[0], get [1,2,3] and [2,1,3]
        // swap nums[2] with nums[0]~nums[2], get [3,2,1],[1,3,2],[1,2,3] and [3,1,2],[2,3,1],[2,1,3]
        for(int i = 1; i < res.size(); i++) {
            int j = rand() % (i+1);
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

